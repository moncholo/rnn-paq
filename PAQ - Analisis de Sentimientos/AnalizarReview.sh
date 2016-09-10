#!/bin/bash

#set +H y -H deshabilita y habilita respectivamente el history expansion para 
#que pueda interpretarse el signo de exclamacion como un caracter 
#y no como un comando de bash
#---------------
#set -H es el default, cuidado

set +H
echo $1 > paq8n-negativos/review.txt
echo $1 > paq8n-positivos/review.txt
echo $1 > review.txt
set -H

TAM_REVIEW=$(wc -c review.txt | awk '{print $1}');

#----------------POSITIVOS----------------------
echo "Comenzando análisis con el Set de los Positivos";

rm -f paq8n-positivos/ReviewPositivo.paq8n

cp paq8n-positivos/Backup/ReviewPositivo.paq8n paq8n-positivos/ReviewPositivo.paq8n

cr_restart paq8n-positivos/CheckpointPositivos;

sed -i "s/[0-9]*\(.review.txt\)/$TAM_REVIEW\1/" paq8n-positivos/ReviewPositivo.paq8n;

#es el tamaño comprimido de la carpeta /pos80
TAM_POSITIVOS=$(wc -c paq8n-original/Positivos.paq8n | awk '{print $1}')
#es el tamaño comprimido de la carpeta /pos80 con el archivo de review
TAM_POSITIVOSCONREVIEW=$(wc -c paq8n-positivos/ReviewPositivo.paq8n | awk '{print $1}')

DIFERENCIA_POSITIVA=$((TAM_POSITIVOSCONREVIEW-TAM_POSITIVOS))

#--------------NEGATIVOS-------------------------

echo "Comenzando análisis con el Set de los Negativos"

rm -f paq8n-negativos/ReviewNegativo.paq8n

cp paq8n-negativos/Backup/ReviewNegativo.paq8n paq8n-negativos/ReviewNegativo.paq8n

cr_restart paq8n-negativos/CheckpointNegativos

sed -i "s/[0-9]*\(.review.txt\)/$TAM_REVIEW\1/" paq8n-negativos/ReviewNegativo.paq8n

TAM_NEGATIVOS=$(wc -c paq8n-original/Negativos.paq8n | awk '{print $1}')

TAM_NEGATIVOSCONREVIEW=$(wc -c paq8n-negativos/ReviewNegativo.paq8n | awk '{print $1}')

DIFERENCIA_NEGATIVA=$((TAM_NEGATIVOSCONREVIEW-TAM_NEGATIVOS))


#-------------------RESULTADOS-------------------#

echo "La compresion obtenida con reviews positivos es de $DIFERENCIA_POSITIVA bytes"
echo "La compresion obtenida con reviews negativos es de $DIFERENCIA_NEGATIVA bytes"

if [ "$2" == "p" ]
then	
	if [ $DIFERENCIA_POSITIVA -lt $DIFERENCIA_NEGATIVA ];then
		echo "PASSED"
		echo "PASSED: $1" >> Resultados80.txt
		echo "Deberia dar Positivo y dio Positivo" >> Resultados80.txt
	else
		echo "FAILED: $1" >> Resultados80.txt
		echo "FAILED"
		echo "Deberia dar Positivo y dio Negativo" >> Resultados80.txt
	fi
	
elif [ "$2" == "n" ]
then
	if [ $DIFERENCIA_NEGATIVA -lt $DIFERENCIA_POSITIVA ];then
		echo "PASSED: $1" >> Resultados80.txt
		echo "PASSED"
		echo "Deberia dar Negativo y dio Negativo" >> Resultados80.txt
	else
		echo "FAILED"		
		echo "FAILED: $1" >> Resultados80.txt
		echo "Deberia dar Negativo y dio Positivo" >> Resultados80.txt
	fi
else
	if [ $DIFERENCIA_POSITIVA -lt $DIFERENCIA_NEGATIVA ]
	then
		echo "El review se predice Positivo"
	elif [ $DIFERENCIA_POSITIVA -gt $DIFERENCIA_NEGATIVA ] 
	then
		echo "El review se predice Negativo"	
	else
		echo "El review se predice Inconcluso"
	fi	
fi

echo "Diferencia negativa: $DIFERENCIA_NEGATIVA" >> Resultados80.txt
echo "Diferencia positiva: $DIFERENCIA_POSITIVA" >> Resultados80.txt
echo "-----------------------------------------" >> Resultados80.txt
