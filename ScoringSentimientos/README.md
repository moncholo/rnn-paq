
#Para Analizar si un review es positivo, se debera utilizar el script scoring.sh que recibe dos parámetros:

1) Contenido a analizar

2) Letra "p" o "n" para indicar si el contenido a analizar es positivo o negativo

A modo ejemplo:

./scoring.sh "That's the best movie I've ever seen in my life" p

De esta forma, le indicamos al script que el contenido que ingresamos es positivo, y el script arrojará su predicción. En este caso, el resultado arrojado en consola es el siguiente:

El acumulado es: 3
PASSED

También hay un archivo llamado Resultados80.txt donde se registran todos los reviews que se van analizando. Para este ejemplo, se puede encontrar el siguiente resultado en el archivo:

PASSED: That's the best movie I've ever seen
Deberia dar Positivo y dio Positivo
Puntaje acumulado: 3

Si el puntaje acumulado es mayor que cero, entonces el review se predice como positivo; si es menor que cero se predice como negativo y si es igual a cero es inconcluso. PASSED significa que la predicción fue hecha correctamente, y FAILED incorrrectamente.

En la carpeta pos/ y neg/ hay 2492 y 2500 reviews positivos y negativos respectivamente para ser analizados. 
El script Analizar.sh se encarga de agarrar todos y cada uno de los reviews de ambas carpetas y los analiza llamando internamente al script scoring.sh. 

Para llamar al script que analiza a todos los reviews, correr:

./Analizar.sh



