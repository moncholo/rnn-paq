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

laplace =  len(f_obs) - len(f_exp);

if (len(f_exp) < len(f_obs)):
	for x in range(0, len(f_exp)):
		f_exp[x] += laplace;


if (len(f_exp) < len(f_obs)):
	for x in range(0, laplace):
		f_exp += [1];

suma_observado = sum(f_obs)
suma_esperado = sum(f_exp)

for x in range(0, len(f_exp)):
	f_exp[x] = f_exp[x]*suma_observado;
	f_exp[x] = f_exp[x] / suma_esperado;

(statistic, pvalue) = chisquare(f_obs,f_exp);

print "%f,%d" %( statistic, laplace);

