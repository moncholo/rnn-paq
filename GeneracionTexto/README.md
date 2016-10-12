Primero se debe compilar el entrenador de  PAQ con el siguiente comando:

g++ -std=c++11 paq8n.cpp -O2 -DUNIX -DNOASM -s -o TrainPAQ -LBLCR_LIBDIR -lcr_run -u cr_run_link_me

Luego, correr el siguiente comando para entrenar PAQ con un texto dado (en modo root):

cr_run ./TrainPAQ -8 [filename]

Por ejemplo:

cr_run ./TrainPAQ -8 README.md


Al ejecutar dicho comando, se generará un archivo con la siguiente nomenclatura:

filename_sizeOf(filename)_level_time_maxMemUsed_PAQ_Checkpoint

Por ejemplo:

enwik8_size:100000000_level:8_time:14182.974381_maxMem:1643547347_PAQ_Checkpoint

El parámetro tiempo es el tiempo de entrenamiento utilizado.

El parámetro maxMem es la máxima memoria utilizada en bytes.

El parámetro level es el nivel de entrenamiento (o compresión) utilizado.


Luego, para poder generar una cadena de caracteres, se deberá correr el siguiente comando e ingresar la cantidad de caracteres que se quiere generar:

cr_restart nombreCheckpoint

Por ejemplo:

cr_restart enwik8_size:100000000_level:8_time:14182.974381_maxMem:1643547347_PAQ_Checkpoint


El resultado será arrojado por consola. Si se quisiera guardar el resultado en un archivo, correr el comando siguiente:

cr_restart nombreCheckpoint > archivoSalida.txt

