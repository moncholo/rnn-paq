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

for x in range(0, len(f_exp)):
	if ((f_exp[x]>0) and (f_obs[x]>0)):
		intersection+=1;	

union = len(f_obs);

jac = intersection/union;

print "jaccard: %f" %(jac);

