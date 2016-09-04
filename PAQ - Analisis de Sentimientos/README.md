#Instrucciones

## Compresor original

Con el compresor original se comprimirá tanto el set de datos positivos como negativos sin el review. Este compresor no tiene modificación alguna

Primero se debe compilar PAQ de la siguiente forma: 

cd paq8n-original/
g++ -std=c++11 paq8n.cpp -O2 -DUNIX -DNOASM -s -o paq8n 

Luego, PAQ debe correrse con el siguiente comando:

./paq8n -level files

El "level" es un número entero entre 0 y 8, yendo de menor a mayor memoria para la compresión.
Será necesario comprimir el set positivo y negativo con los siguientes comandos:

./paq8n -8 Positivos pos80/ 

./paq8n -8 Negativos neg80/



## Compresor Negativo

Instrucción en construcción

## Compresor Positivo

Instrucción en construcción



## Acerca de Serialización con BLCR
Para hacer un checkpoint se ejecuta desde otra terminal (en modo root):

cr_run ./paq8n [argumentos]

cr_checkpoint --file nombre-checkpoint --term PID

Para restaurar el proceso:

cr_restart nombre-checkpoint


La carpeta paq8n-original contiene el compresor sin modificacion alguna.
Con ese compresor se comprimen la carpeta pos/ y neg/ para tener las compresiones
sin modificacion alguna. De esas dos compresiones nos va a interesar el tamaño.

La carpeta paq8n-positivos tiene el compresor modificado para comprimir
la carpeta pos80/ y el archivo review.txt a diferencia que, una vez comprimido 
la carpeta pos/ se realiza un checkpoint para luego levantarlo y que siga comprimiendo
el archivo review.txt al cual se le pueden settear nuevos contenidos
Idem para la carpeta paq8n-negativos pero para la carpeta /neg

--El archivo ReviewPositivo80v2.paq8n es el archivo comprimido congelado que tiene los reviews de la carpeta pos80/ y el review.txt
--El archivo CheckpointPositivosv2 es la nueva imagen de BLCR para levantar nuevamente el proceso.

Idem con los negativos


Una vez realizado el cr_restart Checkpoint[Positivo|Negativo] se
debe modificar el header del archivo comprimido para que despues
al descomprimirlo se obtengan los archivos originales.
El comando para realizar eso es un SED:

sed -i "s/[0-9]*\(.review.txt\)/$TAM_ARCHIVO_REVIEW\1/" ComprimidoConReview.paq8n
