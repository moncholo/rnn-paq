#!/bin/bash

for fileParte in $1/parte/*; do
	
	for filePAQ in $1/PAQ/*; do
		./Distribucion 4 $fileParte $filePAQ
		resultado_chi=`./chi.py`
		resultado_total=`./totalvariation.py`
		./Distribucion 10 $fileParte $filePAQ
		resultado_jaccard=`./jaccard.py`
		echo $filePAQ "," $resultado_chi "," $resultado_total "," $resultado_jaccard "," $fileParte >> ResultadosMetricas.txt
	done
done

