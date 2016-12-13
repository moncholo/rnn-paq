#!/bin/bash

for filePAQ in $1/PAQ/*; do
	../../GeneracionTexto/metricas/Distribucion 10 $1/input.txt $filePAQ
	resultado_jaccard=`../../GeneracionTexto/metricas/jaccard.py`
	echo $filePAQ "," $resultado_jaccard  >> ResultadosMetricasJaccardSinEsperanza.txt
done

