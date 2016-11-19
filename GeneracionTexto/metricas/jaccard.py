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

intersection = 0.000000;
union = 0.000000;

rango= 0;
rangoMax= 0;

#me quedo con el tamanio minimo

if(len(f_exp) > len(f_obs)):
	rango= len(f_obs);
	rangoMax = len(f_exp);

else:
	rango= len(f_exp);
	rangoMax = len(f_obs);


for x in range(0, rango):
	intersection+=min(f_exp[x], f_obs[x]);		
	union+=max(f_exp[x], f_obs[x]);

if(len(f_exp) > len(f_obs)):
	for x in range(rango+1, rangoMax):
		union+=f_exp[x];
			
else:
	for x in range(rango+1, rangoMax):
		union+=f_obs[x];

jac = intersection/union;

print "%f" %(jac);

