#!/bin/bash


for file in pos/*; do
	contenido=$(cat $file)

	./scoring.sh "$contenido" p

	contenido=""

	echo $file >> Resultados80.txt


	i=$((i+1))
done


for file in neg/*; do
	contenido=$(cat $file)

	./scoring.sh "$contenido" n

	contenido=""

	echo $file >> Resultados80.txt

	i=$((i+1))

done



