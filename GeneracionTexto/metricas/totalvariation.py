#!/usr/bin/python
import sys

f = open("entrada.frecuencias");
f2 = open("generado.frecuencias");

str = f.readline();
str2 = f2.readline();

f.close();
f2.close();

f_exp = [float(x) for x in str.split(';')];
f_obs = [float(x) for x in str2.split(';')];

suma_observado = sum(f_obs)
suma_esperado = sum(f_exp)

suma = 0.0;
suma2= 0.0;
rango= 0;

if(len(f_exp) > len(f_obs)):
	rango= len(f_exp);
else:
	rango= len(f_obs);

for x in range(0, rango):
	
	if(len(f_exp) > x):
		suma2= suma2+ abs(f_exp[x]/suma_esperado - f_obs[x]/suma_observado);
		
		if((f_exp[x]/suma_esperado) > (f_obs[x]/suma_observado)):
			suma = suma + f_obs[x]/suma_observado;

		else:
			suma = suma + f_exp[x]/suma_esperado;

	else:
		suma2= suma2+ f_obs[x]/suma_observado;


print "%f" %(suma2/2);

