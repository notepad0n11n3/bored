import sys
import numpy as np
from xgboost import XGBClassifier
from sklearn.multioutput import MultiOutputClassifier

# --- Leer archivo test con solo combinaciones ---
def cargar_combinaciones(path):
    data = []
    with open(path, 'r', encoding='utf-8') as f:
        for linea in f:
            try:
                numeros = list(map(int, linea.strip().split()))
                if len(numeros) != 6:
                    continue
                vector = [0] * 50
                for n in numeros:
                    if 1 <= n <= 50:
                        vector[n - 1] = 1
                data.append(vector)
            except Exception:
                continue
    return np.array(data)

# --- Entrenamiento y predicción de una sola combinación ---
def predecir_una_combinacion(data, top_n=6, window_size=3):
    X, y = [], []
    for i in range(window_size, len(data)):
        X.append(np.concatenate(data[i - window_size:i]))
        y.append(data[i])
    X, y = np.array(X), np.array(y)

    model = MultiOutputClassifier(XGBClassifier(tree_method="hist", eval_metric="logloss"))
    model.fit(X, y)

    entrada = np.concatenate(data[-window_size:]).reshape(1, -1)
    proba = model.predict_proba(entrada)
    probs = np.array([p[1] if len(p) > 1 else 0.0 for p in proba])
    pred = probs.argsort()[::-1][:top_n]

    pred_final = sorted(pred)
    with open("MaybE.txt", "w") as f:
        f.write("{}\n".format(" ".join(str(i + 1).zfill(2) for i in pred_final)))

# --- Main ---
def main():
    if len(sys.argv) != 2:
        print("Uso: python3 a01.py <archivo>")
        sys.exit(1)

    datos = cargar_combinaciones(sys.argv[1])
    if len(datos) < 10:
        print("[!] No hay suficientes combinaciones.")
        sys.exit(1)

    predecir_una_combinacion(datos)
    print("[✓] Predicción guardada en MaybE.txt")

if __name__ == "__main__":
    main()

