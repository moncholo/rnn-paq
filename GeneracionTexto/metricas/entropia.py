#!/usr/bin/python

from scipy.stats import chisquare
import sys
import math

f = open("entropia.frecuencias");

str = f.readline();

f.close();

f_exp = [float(x) for x in str.split(';')];


entropia = 0.0

suma = sum(f_exp);


for x in range(0, len(f_exp)):
	f_exp[x] = f_exp[x]/suma;
 	entropia += f_exp[x]*math.log(f_exp[x])/math.log(2);

entropia=-entropia;
print "%f" %(entropia);

