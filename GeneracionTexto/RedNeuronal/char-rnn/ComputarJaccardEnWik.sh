#!/bin/bash

for fileRNN in $1/RedNeuronal/*; do
	../../GeneracionTexto/metricas/Distribucion 10 $1/input.txt $fileRNN
	resultado_jaccard=`../../GeneracionTexto/metricas/jaccard.py`
	echo $fileRNN "," $resultado_jaccard >> ResultadosJaccardEnWik.txt

done

for filePAQ in $1/PAQ/*; do
	
	../../GeneracionTexto/metricas/Distribucion 10 $1/input.txt $filePAQ
	resultado_jaccard=`../../GeneracionTexto/metricas/jaccard.py`
	echo $filePAQ "," $resultado_jaccard  >> ResultadosJaccardEnWik.txt
done

