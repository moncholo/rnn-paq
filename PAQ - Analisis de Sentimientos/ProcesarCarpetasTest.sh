#!/bin/bash


#El presente script sirve para analizar todos los reviews automaticamente de 
#las carpetas TestPositivos y TestNegativos

for file in TestPositivos/*; do
	contenido=$(cat $file)
	./AnalizarReview.sh "$contenido" p
done


for file in TestNegativos/*; do
	contenido=$(cat $file)
	./AnalizarReview.sh "$contenido" n
done





