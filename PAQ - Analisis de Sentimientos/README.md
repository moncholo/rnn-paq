#Instrucciones

## Acerca de Serialización con BLCR

Para poder utilizar esta libreria, ademas de instalarla, se requerirá insertar el módulo de BLCR en el Kernel de linux cada vez 
que se prende/apaga la computadora. Los comandos son los sigientes y dependeran de la ruta donde se haya instalado BLCR:

/sbin/insmod /usr/local/lib/blcr/3.13.0-24-generic/blcr_imports.ko

/sbin/insmod /usr/local/lib/blcr/3.13.0-24-generic/blcr.ko

PATH=$PATH:/usr/local/bin/

MANPATH=$MANPATH:/usr/local/man/

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib:/usr/local/lib/

export PATH MANPATH LD_LIBRARY_PATH



Para hacer un checkpoint se ejecuta desde otra terminal (en modo root):

cr_run ./paq8n [argumentos]

cr_checkpoint --file nombre-checkpoint --term PID

Para restaurar el proceso:

cr_restart nombre-checkpoint


## Compresor original

Con el compresor original se comprimirá tanto el set de datos positivos como negativos sin el review. Este compresor no tiene modificación alguna

Primero se debe compilar PAQ de la siguiente forma: 

cd paq8n-original/

g++ -std=c++11 paq8n.cpp -O2 -DUNIX -DNOASM -s -o paq8n 

Luego, PAQ debe correrse con el siguiente comando:

./paq8n -level files

El "level" es un número entero entre 0 y 8, yendo de menor a mayor memoria para la compresión.

Será necesario comprimir el set positivo y negativo con los siguientes comandos:

./paq8n -8 Positivos ../SetPositivos/ 

./paq8n -8 Negativos ../SetNegativos/

Al comprimir ambos set, se obtendrán los siguientes dos archivos:

-Positivos.paq8n

-Negativos.paq8n

## Compresor Para Analizar Reviews Negativos

Ir a la carpeta paq8n-negativos

cd ../paq8n-negativos

Se deberá compilar el compresor PAQ autoserializable, con el siguiente comando:

g++ -std=c++11 paq8n.cpp -O2 -DUNIX -DNOASM -s -o paq8n -LBLCR_LIBDIR -lcr_run -u cr_run_link_me


Ahora, se comprimirá el set de negativos junto al review.txt, con el siguiente comando (en modo root):

cr_run ./paq8n -8 ReviewNegativo ../SetNegativos/ review.txt 

Esto generará dos archivos:

-Un archivo llamado ReviewNegativo.paq8n

-Un archivo llamado CheckpointNegativos

Se deberá primero realizar un Backup de ambos archivos, y ponerlos en modo lectura:

cp ReviewNegativo.paq8n Backup/

cp CheckpointNegativos Backup/

chmod +r Backup/ReviewNegativo.paq8n

chmod +r Backup/CheckpointNegativos

El archivo ReviewNegativo.paq8n contiene la compresión de toda la carpeta SetNegativos/ pero aún le falta completar
la compresión del archivo review.txt.

El archivo CheckpointNegativos es aquel que con un comando especial reinicia la compresión del archivo ReviewNegativo.paq8n
y termina de comprimir el archivo review.txt. (El comando es el siguiente pero NO ejecutar en esta instancia):

cr_restart CheckpointNegativos


## Compresor Para Analizar Reviews Positivos

Ir a la carpeta paq8n-positivos

cd ../paq8n-positivos

Se deberá compilar el compresor PAQ autoserializable, con el siguiente comando:

g++ -std=c++11 paq8n.cpp -O2 -DUNIX -DNOASM -s -o paq8n -LBLCR_LIBDIR -lcr_run -u cr_run_link_me


Ahora, se comprimirá el set positivo junto al review.txt, con el siguiente comando (en modo root):

cr_run ./paq8n -8 ReviewPositivo SetPositivos/ review.txt 

Esto generará dos archivos:

-Un archivo llamado ReviewPositivo.paq8n

-Un archivo llamado CheckpointPositivos

Se deberá primero realizar un Backup de ambos archivos, y ponerlos en modo lectura:

cp ReviewPositivo.paq8n Backup/

cp CheckpointPositivos Backup/

chmod +r Backup/ReviewPositivo.paq8n

chmod +r Backup/CheckpointPositivos

El archivo ReviewPositivo.paq8n contiene la compresión de toda la carpeta SetPositivos/ pero aún le falta completar
la compresión del archivo review.txt.

El archivo CheckpointPositivos es aquel que con un comando especial reinicia la compresión del archivo ReviewPositivo.paq8n
y termina de comprimir el archivo review.txt. (El comando es el siguiente pero NO ejecutar en esta instancia):

cr_restart CheckpointPositivos


## Cómo Analizar Un Review

Para poder analizar un review, se debera usar el script AnalizarReview.sh. Para ello (en modo root):

cd ../

chmod +x AnalizarReview.sh

./AnalizarReview.sh "That's the best movie I've ever seen in my life"
