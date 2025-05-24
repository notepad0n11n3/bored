import sys
import pandas as pd
import numpy as np
from datetime import datetime
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.decomposition import PCA
from sklearn.cluster import KMeans
from sklearn.multioutput import MultiOutputClassifier
from sklearn.model_selection import train_test_split
from xgboost import XGBClassifier

# --- Utilidades ---
def parse_file(filepath):
    data = []
    with open(filepath, 'r', encoding='utf-8') as f:
        for line in f:
            parts = line.strip().split('\t')
            if len(parts) != 3:
                continue
            fecha_str, id_str, numeros_str = parts
            try:
                fecha = datetime.strptime(fecha_str, "%d/%m/%Y")
                id_sorteo = int(id_str)
                numeros = list(map(int, numeros_str.strip().split()))
                vector = [0] * 50
                for num in numeros:
                    if 1 <= num <= 50:
                        vector[num - 1] = 1
                data.append({"fecha": fecha, "id": id_sorteo, "numeros": numeros, "vector": vector})
            except:
                continue
    return pd.DataFrame(data)

# --- Graficar coocurrencia ---
def plot_coocurrence(df):
    cooc = np.zeros((50, 50), dtype=int)
    for vector in df["vector"]:
        indices = [i for i, v in enumerate(vector) if v == 1]
        for i in indices:
            for j in indices:
                if i != j:
                    cooc[i, j] += 1
    plt.figure(figsize=(12, 10))
    sns.heatmap(cooc, cmap="magma", square=True)
    plt.title("Mapa de Coocurrencia entre Números")
    plt.xlabel("Número")
    plt.ylabel("Número")
    plt.tight_layout()
    plt.savefig("coocurrence_heatmap.png")
    plt.close()

# --- Clustering y PCA ---
def cluster_vectors(df):
    vectors = np.array(df["vector"].tolist())
    pca = PCA(n_components=2)
    reduced = pca.fit_transform(vectors)
    kmeans = KMeans(n_clusters=5, random_state=42).fit(reduced)
    plt.figure(figsize=(10, 8))
    plt.scatter(reduced[:, 0], reduced[:, 1], c=kmeans.labels_, cmap='tab10', s=10)
    plt.title("Clustering de combinaciones (PCA + KMeans)")
    plt.savefig("clusters.png")
    plt.close()

# --- Modelado predictivo con XGBoost ---
def predict_next(df):
    X = np.array(df["vector"].tolist())[:-1]
    y = np.array(df["vector"].tolist())[1:]  # Predecir la combinación siguiente

    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
    model = MultiOutputClassifier(XGBClassifier(tree_method="hist", eval_metric="logloss"))
    model.fit(X_train, y_train)

    last_vector = X[-1].reshape(1, -1)
    prediction = model.predict(last_vector)[0]
    pred_numbers = [str(i+1).zfill(2) for i, v in enumerate(prediction) if v == 1]

    with open("MaybE.txt", "w") as f:
        f.write("Prediccion (posiciones 1-50):\n")
        f.write(" ".join(pred_numbers) + "\n")

# --- Main ---
def main():
    if len(sys.argv) != 2:
        print("Uso: python3 predictor.py <archivo>")
        sys.exit(1)

    filepath = sys.argv[1]
    df = parse_file(filepath)

    print("[+] Datos cargados: {} sorteos".format(len(df)))

    print("[+] Generando mapa de coocurrencia...")
    plot_coocurrence(df)

    print("[+] Ejecutando clustering...")
    cluster_vectors(df)

    print("[+] Entrenando modelo y generando prediccion...")
    predict_next(df)

    print("[✓] Prediccion guardada en MaybE.txt")

if __name__ == "__main__":
    main()

