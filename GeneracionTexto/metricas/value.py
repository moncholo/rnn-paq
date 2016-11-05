#!/usr/bin/python
from scipy.stats import chisquare
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

for x in range(0, len(f_exp)):
	if((f_exp[x]/suma_esperado) > (f_obs[x]/suma_observado)):
		suma = suma + f_obs[x]/suma_observado;

	else:
		suma = suma + f_exp[x]/suma_esperado

print "value: %f" %( suma);

