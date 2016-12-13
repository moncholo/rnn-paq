#!/bin/bash

sed 's/\.//g;s/\(.*\)/\L\1/;s/\ /\n/g;s/,/\n/g' $1 | sort | uniq -c > $1.tokenize;
sed 's/\.//g;s/\(.*\)/\L\1/;s/\ /\n/g;s/,/\n/g' $2 | sort | uniq -c > $2.tokenize;

sed 's/\(.*\)\([0-9]*\) \(.*\)/\3/' $1.tokenize  > $1.palabras;
sed 's/\(.*\)\([0-9]*\) \(.*\)/\3/' $2.tokenize  > $2.palabras;

#esto me devuelve palabras que estan en el texto 2 que no estan en el texto uno

comm -13 <(sort $1.palabras) <(sort $2.palabras) | sed 's/\(.*\)/0 \1/' >> $1.tokenize

#esto me devuelve palabras que estan en el texto 1 que no estan en el texto dos
comm -13 <(sort $2.palabras) <(sort $1.palabras) | sed 's/\(.*\)/0 \1/' >> $2.tokenize

sed 's/\(.*\)\([0-9]*\) \(.*\)/\3 \1/' $2.tokenize  > $2.tokenize2;

join <(sort $1.tokenize2) <(sort $2.tokenize2) 
