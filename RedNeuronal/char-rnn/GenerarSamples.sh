#!/bin/bash

for file in Resultados/*; do
	#obtendo el id de cada checkpoint
	id=$(echo $file | grep -o 'id_...')
	echo $file	
	th sample.lua -length 100000 -temperature 0.20 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.20_len100000.txt"
	th sample.lua -length 100000 -temperature 0.23 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.23_len100000.txt"
	th sample.lua -length 100000 -temperature 0.26 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.26_len100000.txt"
	th sample.lua -length 100000 -temperature 0.29 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.29_len100000.txt"
	th sample.lua -length 100000 -temperature 0.32 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.32_len100000.txt"
	th sample.lua -length 100000 -temperature 0.35 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.35_len100000.txt"
	th sample.lua -length 100000 -temperature 0.38 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.38_len100000.txt"
	th sample.lua -length 100000 -temperature 0.41 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.41_len100000.txt"
	th sample.lua -length 100000 -temperature 0.44 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.44_len100000.txt"
	th sample.lua -length 100000 -temperature 0.47 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.47_len100000.txt"
	th sample.lua -length 100000 -temperature 0.50 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.50_len100000.txt"
	th sample.lua -length 100000 -temperature 0.53 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.53_len100000.txt"
	th sample.lua -length 100000 -temperature 0.56 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.56_len100000.txt"
	th sample.lua -length 100000 -temperature 0.59 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.59_len100000.txt"
	th sample.lua -length 100000 -temperature 0.60 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.60_len100000.txt"
	th sample.lua -length 100000 -temperature 0.63 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.63_len100000.txt"
	th sample.lua -length 100000 -temperature 0.66 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.66_len100000.txt"
	th sample.lua -length 100000 -temperature 0.69 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.69_len100000.txt"
	th sample.lua -length 100000 -temperature 0.72 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.72_len100000.txt"
	th sample.lua -length 100000 -temperature 0.75 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.75_len100000.txt"
	th sample.lua -length 100000 -temperature 0.78 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.78_len100000.txt"
	th sample.lua -length 100000 -temperature 0.82 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.82_len100000.txt"
	th sample.lua -length 100000 -temperature 0.84 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.84_len100000.txt"
	th sample.lua -length 100000 -temperature 0.86 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.86_len100000.txt"
	th sample.lua -length 100000 -temperature 0.88 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.88_len100000.txt"
	th sample.lua -length 100000 -temperature 0.90 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.90_len100000.txt"
	th sample.lua -length 100000 -temperature 0.92 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.92_len100000.txt"
	th sample.lua -length 100000 -temperature 0.94 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.94_len100000.txt"
	th sample.lua -length 100000 -temperature 0.96 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.96_len100000.txt"
	th sample.lua -length 100000 -temperature 0.98 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.98_len100000.txt"
	th sample.lua -length 100000 -temperature 1.00 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp1.00_len100000.txt"
	mv $file Procesados/
done

