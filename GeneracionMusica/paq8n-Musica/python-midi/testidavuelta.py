import midi
pattern = midi.read_midifile("Nottingham/ashover_simple_chords_1.mid")
#print pattern
midi.write_midifile("example.mid", pattern)

data = midi.Pattern()
data = open("unacancionsola.txt").read()
print data
midi.write_midifile("example2.mid", data)

