#!/bin/bash

for filePAQ in $1/PAQ/*; do	
	echo $filePAQ
	../../GeneracionTexto/metricas/Distribucion 4 $1/input.txt $filePAQ

	resultado_chi=`../../GeneracionTexto/metricas/chi.py`
	resultado_total=`../../GeneracionTexto/metricas/totalvariation.py`
	../../GeneracionTexto/metricas/Distribucion 10 $1/input.txt $filePAQ
	resultado_jaccard=`../../GeneracionTexto/metricas/jaccardConEsperanza.py`
	echo $filePAQ "," $resultado_chi "," $resultado_total "," $resultado_jaccard  >> ResultadosMetricas.txt
done

