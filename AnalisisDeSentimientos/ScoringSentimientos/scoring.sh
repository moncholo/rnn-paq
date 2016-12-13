#!/bin/bash
#el parametro 1 recibe el contenido a analizar

set +H
echo $1 > review.txt
set -H

#-----------------------------------------

acumulado=0

for word in $(<review.txt); 
do 


#La siguiente regexp se utiliza para limpiar cada una de las palabras que pueden tener algun caracter no deseado
word=$(echo "$word" |  sed 's/,//g' | sed 's/\.//g' | sed 's/\?//g' | sed 's/¿//g' | sed 's/\!//g'| sed 's/\¡//g'| sed 's/://g' | sed 's/<//g' | sed 's/>//g' | sed 's/;//g' | sed 's/\*//g' | sed 's/\+//g' | sed 's/\"//g' | sed 's/(//g' | sed 's/)//g' | sed 's/\///g' | sed 's/\\//g' | tr '[:upper:]' '[:lower:]'
);


puntaje=$(grep -P '^'${word}'\t[0-9]*' AFINN-111.txt | sed 's/\(^'${word}'\t\)\([0-9]*\)/\2/');

if [ ! -z "$puntaje" ]; then


acumulado=$((acumulado+puntaje))
fi

done

echo "El acumulado es: $acumulado";

if [ "$2" == "p" ];then	
	if [ $acumulado -gt 0 ];then
		echo "PASSED"
		echo "PASSED: $1" >> Resultados80.txt
		echo "Deberia dar Positivo y dio Positivo" >> Resultados80.txt
	else
		echo "FAILED: $1" >> Resultados80.txt
		echo "FAILED"
		echo "Deberia dar Positivo y dio Negativo" >> Resultados80.txt
	fi
	
fi

if [ "$2" == "n" ];then
	if [ $acumulado -lt 0 ];then
		echo "PASSED: $1" >> Resultados80.txt
		echo "PASSED"
		echo "Deberia dar Negativo y dio Negativo" >> Resultados80.txt
	else
		echo "FAILED"		
		echo "FAILED: $1" >> Resultados80.txt
		echo "Deberia dar Negativo y dio Positivo" >> Resultados80.txt
	fi
fi

echo "Puntaje acumulado: $acumulado" >> Resultados80.txt

echo "-----------------------------------------------------------------------" >> Resultados80.txt


