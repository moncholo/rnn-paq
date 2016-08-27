El archivo scoring.sh recibe dos parametros:
1) Contenido a analizar
2) Letra "p" o "n" para indicar si el contenido a analizar es positivo o negativo

Luego, en base a eso realiza un tokenize de cada palabra y busca los puntajes en el archivo de puntajes, y los sumariza. Si dan
mayores que cero es porque es positivo, si dan menos que cero es porque son negativos.

El archivo Analizar.sh se encarga de agarrar todos y cada uno de los archivos a procesar y llamar al script scoring.sh


