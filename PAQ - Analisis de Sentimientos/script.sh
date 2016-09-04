#!/bin/bash

i=0
cantidad=50
for file in setPruebaPositivos/*; do
contenido=$(cat $file)
if [ $i == $cantidad ]; then
	break
fi
./Analizar8020.sh "$contenido" p
contenido=""
echo $file >> Resultados80.txt
echo "-----------------------------------------------------------------------" >> Resultados80.txt

rm -f $file
i=$((i+1))
done

i=0
cantidad=50
for file in setPruebaNegativos/*; do
contenido=$(cat $file)
if [ $i == $cantidad ]; then
	break
fi
./Analizar8020.sh "$contenido" n
contenido=""
echo $file >> Resultados80.txt
echo "-----------------------------------------------------------------------" >> Resultados80.txt
rm -f $file
i=$((i+1))
done

./script.sh





