#!/bin/bash

for file in Resultados/*; do
	#obtendo el id de cada checkpoint
	id=$(echo $file | grep -o 'id_...')
	echo $file	
	th sample.lua -length 100000 -temperature 0.20 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.20_len100000.txt"
	th sample.lua -length 100000 -temperature 0.40 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.40_len100000.txt"
	th sample.lua -length 100000 -temperature 0.60 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.60_len100000.txt"
	th sample.lua -length 100000 -temperature 0.80 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.80_len100000.txt"
	th sample.lua -length 100000 -temperature 0.81 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.81_len100000.txt"
	th sample.lua -length 100000 -temperature 0.82 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.82_len100000.txt"
	th sample.lua -length 100000 -temperature 0.83 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.83_len100000.txt"
	th sample.lua -length 100000 -temperature 0.84 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.84_len100000.txt"
	th sample.lua -length 100000 -temperature 0.85 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.85_len100000.txt"
	th sample.lua -length 100000 -temperature 0.86 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.86_len100000.txt"
	th sample.lua -length 100000 -temperature 0.87 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.87_len100000.txt"
	th sample.lua -length 100000 -temperature 0.88 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.88_len100000.txt"
	th sample.lua -length 100000 -temperature 0.89 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.89_len100000.txt"
	th sample.lua -length 100000 -temperature 0.90 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.90_len100000.txt"
	th sample.lua -length 100000 -temperature 0.91 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.91_len100000.txt"
	th sample.lua -length 100000 -temperature 0.92 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.92_len100000.txt"
	th sample.lua -length 100000 -temperature 0.93 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.93_len100000.txt"
	th sample.lua -length 100000 -temperature 0.94 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.94_len100000.txt"
	th sample.lua -length 100000 -temperature 0.95 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.95_len100000.txt"
	th sample.lua -length 100000 -temperature 0.96 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.96_len100000.txt"
	th sample.lua -length 100000 -temperature 0.97 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.97_len100000.txt"
	th sample.lua -length 100000 -temperature 0.98 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.98_len100000.txt"
	th sample.lua -length 100000 -temperature 0.99 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp0.99_len100000.txt"
	th sample.lua -length 100000 -temperature 1.00 -gpuid -1 -verbose 0 $file > Muestras/$id"_temp1.00_len100000.txt"
	mv $file Procesados/
done

