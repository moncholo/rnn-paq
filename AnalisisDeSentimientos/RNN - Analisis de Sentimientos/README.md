#Analisis de Sentimientos con Red Neuronal

En la presente sección se podrá realizar análisis de sentimientos sobre un set de datos utilizando la Red Neuronal de Stanford, que se puede obtener del siguiente link:

`http://nlp.stanford.edu/sentiment/index.html`

Existen dos carpetas que deberán cargarse con archivos

`pos: Se deberán cargar los reviews positivos a clasificar por la red`

`neg: Se deberán cargar los reviews negativos a clasificar por la red`


Luego, se deberá correr el siguiente comando:

`sh script.sh`

El script realizará la clasificación de sentimientos sobre cada archivo ubicado en las carpetas anteriores, y una vez que los clasifique los moverá según corresponda a alguna de las dos siguientes carpetas:

`Procesados/pos`

`Procesados/neg`

La Red Neuronal se encarga de procesar todos y cada uno de los archivos. Para cada archivo, analiza sus frases y les asigna uno de los siguientes cinco puntajes posibles:

`Very Negative: -2`

`Negative: -1`

`Neutral: 0`

`Positive: 1`

`Very Positive: 2`


Los resultados serán almacenados en el archivo Resultados.txt. Un ejemplo será el siguiente:

`Archivo: ../pos/10000_8.txt, Es: Positivo, Negative: 8, Positive: 1, Very negative: 0, Very positive: 0, Neutral: 4, Suma: -7`

El resultado anterior significa que al archivo `10000_8.txt` se le han asignad 8 frases negativas, 1 positiva y 4 neutrales. En consecuencia, la suma será (-1)*8 + 1*1 + 0*4 = -7
 


