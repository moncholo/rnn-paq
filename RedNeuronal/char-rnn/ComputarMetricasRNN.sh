#!/bin/bash

for fileRNN in $1/RedNeuronal/*; do
	../../GeneracionTexto/metricas/Distribucion 4 $1/input.txt $fileRNN
	resultado_chi=`../../GeneracionTexto/metricas/chi.py`
	resultado_total=`../../GeneracionTexto/metricas/totalvariation.py`
	../../GeneracionTexto/metricas/Distribucion 10 $1/input.txt $fileRNN
	resultado_jaccard=`../../GeneracionTexto/metricas/jaccardConEsperanza.py`
	echo $fileRNN "," $resultado_chi "," $resultado_total "," $resultado_jaccard >> ResultadosMetricas.txt

done
