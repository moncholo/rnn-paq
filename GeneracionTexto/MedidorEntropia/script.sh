#En el parametro 1 se recibe la ruta del archivo Comprimido Original
#En el parametro 2 se recibe el directorio de textos generados
#En el parametro 3 se recibe el nombre del Checkpoint
#En el parametro 4 se recibe el nombre del archivo Comprimido concatenado



#El parametro comprimido se guarda en una copia con la leyenda Original para identificarlo
rm -f $4 
cp Backup/$4 $4


#Se carga en input.txt el contenido del texto generado por PAQ
#Luego se reinicializa el Checkpoint para que comprima el original + el generado

#es el tamaño comprimido del original comprimido
TAM_ORIGINAL=$(wc -c $1 | awk '{print $1}')

echo "Tamanio original $TAM_ORIGINAL"

for file in $2/*; do
	rm -f input.txt
	cat $file >> input.txt

	echo "1" | cr_restart $3

	#es el tamaño comprimido del original con el primer archivo concatenado
	TAM_CONCATENADO=$(wc -c $4 | awk '{print $1}')

	DIFERENCIA=$((TAM_CONCATENADO-TAM_ORIGINAL))
	echo "$1,$file,$DIFERENCIA" >> Resultados.txt
	rm -f $4 
	cp Backup/$4 $4

done


echo "Tamanio concatenado 1 $TAM_CONCATENADO"
echo "Diferencia 1 $DIFERENCIA1"



