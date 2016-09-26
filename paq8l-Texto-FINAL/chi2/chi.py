#!/usr/bin/python
from scipy.stats import chisquare
import sys

f = open("entrada.frecuencias");
f2 = open("generado.frecuencias");

str = f.readline();
str2 = f2.readline();

f.close();
f2.close();

f_exp = [int(x) for x in str.split(';')];
f_obs = [int(x) for x in str2.split(';')];

if (len(f_exp) > len(f_obs)):
	for x in range(0, len(f_exp) - len(f_obs)):
		f_obs += [1];
else:
	for x in range(0, len(f_obs) - len(f_exp)):
		f_exp += [1];

chisquare(f_obs,f_exp)
