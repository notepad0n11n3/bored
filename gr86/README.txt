			
				12/09/2021	-<>-  newMachine

El script a01 usara las siguientes bibliotecas:

	::: pip install pandas numpy matplotlib seaborn xgboost scikit-learn


Crea un entorno virtual(Recomendado), no me dejaba instalar las bibliotecas con pip
				python3 -m venv venv		##  python3 -m venv my_proyect
				source venv/bin/activate
				pip install --upgrade pip
				pip install pandas numpy matplotlib seaborn scikit-learn xgboost
				python3 predictor.py test


	## ACTIVAR ENTORNO venv ##
		
		:: cd /proyect/path && source venv/bin/activate

		:: deactivate				"salir/desactivar el entorno virtual...<3 <3 <3"

*** *** *** USO *** *** ***

	::: python3 a01.py test									('test historial/registro since_1994')


				coocurrence_heatmap.png	-> mapa de ccocurrencia
				clusters.png ->	graficos 2d de clusters
				MaybE.txt	->	predicciones del modelo






### ### Actualizado a02.py ### ###

selecciona las top 10 posiciones mas probables, igual los mete en MaybE.txt

Ajusta el numero de preddiciones <3..
	predict_next(df, top_n=10)			10 predicciones

