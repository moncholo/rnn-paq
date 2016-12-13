#!/bin/bash

rm -f temp.txt

cd stanford-corenlp-full-2016-10-31/

for file in ../pos/*; do
	java -cp "*" -mx5g edu.stanford.nlp.sentiment.SentimentPipeline -file $file -output ROOT > temp.txt
	negative=$(grep -c '^  Negative$' temp.txt)
	verynegative=$(grep -c '^  Very negative$' temp.txt)
	positive=$(grep -c '^  Positive$' temp.txt)
	verypositive=$(grep -c '^  Very positive$' temp.txt)
	neutral=$(grep -c '^  Neutral$' temp.txt)

	suma=$((0*neutral + 1*positive + 2*verypositive - 1*negative - 2*verynegative))
	echo "Archivo: $file, Es: Positivo, Negative: $negative, Positive: $positive, Very negative: $verynegative, Very positive: $verypositive, Neutral: $neutral, Suma: $suma" >> ../Resultados.txt

	rm -f temp.txt
	mv $file ../Procesados/pos
done

for file in ../neg/*; do
	java -cp "*" -mx5g edu.stanford.nlp.sentiment.SentimentPipeline -file $file -output ROOT > temp.txt
	negative=$(grep -c '^  Negative$' temp.txt)
	verynegative=$(grep -c '^  Very negative$' temp.txt)
	positive=$(grep -c '^  Positive$' temp.txt)
	verypositive=$(grep -c '^  Very positive$' temp.txt)
	neutral=$(grep -c '^  Neutral$' temp.txt)

	suma=$((0*neutral + 1*positive + 2*verypositive - 1*negative - 2*verynegative))
	echo "Archivo: $file, Es: Negativo, Negative: $negative, Positive: $positive, Very negative: $verynegative, Very positive: $verypositive, Neutral: $neutral, Suma: $suma" >> ../Resultados.txt

	rm -f temp.txt
	mv $file ../Procesados/neg

done





