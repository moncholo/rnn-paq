#!/usr/bin/python
import sys

contadorDeSegundos=0

with open("salida", 'w') as f:
	for line in open(sys.argv[1]):
		
		#segundos;[nota1 nota2 nota3];volumen
		vector = line.split(";")
		
		#el vector es segundos,notas,volumen
		segundos=vector[0]
		notas=vector[1]
		volumen=vector[2]
		
		#notas es de la forma [4 5 6]
		notasSinCorchetes=notas[1:-1]
		#print "notas %s" %(notas)
		
		
		#notas es de la forma 4 5 6
		listaNotas=notasSinCorchetes.split(" ")
		
		#printeo los ON
		#print "segundos %s" %(contadorDeSegundos)
		for nota in listaNotas:
			linea = str(contadorDeSegundos) + ' On ch=2 n=' + str(nota) + ' v=' + str(volumen)
			f.write(linea)
		
		contadorDeSegundos = contadorDeSegundos + int(segundos)
		
		#printeo los OFF
		for nota in listaNotas:
			linea = str(contadorDeSegundos) + ' Off ch=2 n=' + str(nota) + ' v=' + str(volumen)
			f.write(linea)
