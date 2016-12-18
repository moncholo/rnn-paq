#!/bin/bash
import midi

# mididump.py Nottingham/ashover_simple_chords_1.mid >> unacancionsola.txt

echo "hola"
pattern = midi.read_midifile("Nottingham/ashover_simple_chords_1.mid")
echo "casi"
#print pattern

