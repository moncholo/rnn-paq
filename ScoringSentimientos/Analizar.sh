#!/bin/bash

i=0
cantidad=50
for file in pos/*; do
contenido=$(cat $file)
if [ $i == $cantidad ]; then
	break
fi
./scoring.sh "$contenido" p
contenido=""
echo $file >> Resultados80.txt
echo "-----------------------------------------------------------------------" >> Resultados80.txt

#rm -f $file
i=$((i+1))
done

i=0
cantidad=50
for file in neg/*; do
contenido=$(cat $file)
if [ $i == $cantidad ]; then
	break
fi
./scoring.sh "$contenido" n
contenido=""
echo $file >> Resultados80.txt
echo "-----------------------------------------------------------------------" >> Resultados80.txt
#rm -f $file
i=$((i+1))
done

#./script.sh


