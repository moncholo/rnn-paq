#include "nonstationary.h"

Nonstationary::Nonstationary() : table_{{
1,2,0,0,3,5,1,0,
4,6,0,1,7,9,2,0,
8,11,1,1,8,11,1,1,
10,12,0,2,13,15,3,0,
14,17,2,1,14,17,2,1,
16,19,1,2,16,19,1,2,
18,20,0,3,21,23,4,0,
22,25,3,1,22,25,3,1,
24,27,2,2,24,27,2,2,
26,29,1,3,26,29,1,3,
28,30,0,4,31,33,5,0,
32,35,4,1,32,35,4,1,
34,37,3,2,34,37,3,2,
36,39,2,3,36,39,2,3,
38,41,1,4,38,41,1,4,
40,42,0,5,43,33,6,0,
44,47,5,1,44,47,5,1,
46,49,4,2,46,49,4,2,
48,51,3,3,48,51,3,3,
50,53,2,4,50,53,2,4,
52,55,1,5,52,55,1,5,
40,56,0,6,57,45,7,0,
58,47,6,1,58,47,6,1,
60,63,5,2,60,63,5,2,
62,65,4,3,62,65,4,3,
64,67,3,4,64,67,3,4,
66,69,2,5,66,69,2,5,
52,71,1,6,52,71,1,6,
54,72,0,7,73,59,8,0,
74,61,7,1,74,61,7,1,
76,63,6,2,76,63,6,2,
78,81,5,3,78,81,5,3,
80,83,4,4,80,83,4,4,
82,85,3,5,82,85,3,5,
66,87,2,6,66,87,2,6,
68,89,1,7,68,89,1,7,
70,90,0,8,91,59,9,0,
92,77,8,1,92,77,8,1,
94,79,7,2,94,79,7,2,
96,81,6,3,96,81,6,3,
98,101,5,4,98,101,5,4,
100,103,4,5,100,103,4,5,
82,105,3,6,82,105,3,6,
84,107,2,7,84,107,2,7,
86,109,1,8,86,109,1,8,
70,110,0,9,111,59,10,0,
112,77,9,1,112,77,9,1,
114,97,8,2,114,97,8,2,
116,99,7,3,116,99,7,3,
62,101,6,4,62,101,6,4,
80,83,5,5,80,83,5,5,
100,67,4,6,100,67,4,6,
102,119,3,7,102,119,3,7,
104,121,2,8,104,121,2,8,
86,123,1,9,86,123,1,9,
70,124,0,10,125,59,11,0,
126,77,10,1,126,77,10,1,
128,97,9,2,128,97,9,2,
60,63,8,3,60,63,8,3,
66,69,3,8,66,69,3,8,
104,131,2,9,104,131,2,9,
86,133,1,10,86,133,1,10,
70,134,0,11,135,59,12,0,
136,77,11,1,136,77,11,1,
138,97,10,2,138,97,10,2,
104,141,2,10,104,141,2,10,
86,143,1,11,86,143,1,11,
70,144,0,12,145,59,13,0,
146,77,12,1,146,77,12,1,
148,97,11,2,148,97,11,2,
104,151,2,11,104,151,2,11,
86,153,1,12,86,153,1,12,
70,154,0,13,155,59,14,0,
156,77,13,1,156,77,13,1,
158,97,12,2,158,97,12,2,
104,161,2,12,104,161,2,12,
86,163,1,13,86,163,1,13,
70,164,0,14,165,59,15,0,
166,77,14,1,166,77,14,1,
168,97,13,2,168,97,13,2,
104,171,2,13,104,171,2,13,
86,173,1,14,86,173,1,14,
70,174,0,15,175,59,16,0,
176,77,15,1,176,77,15,1,
178,97,14,2,178,97,14,2,
104,181,2,14,104,181,2,14,
86,183,1,15,86,183,1,15,
70,184,0,16,185,59,17,0,
186,77,16,1,186,77,16,1,
74,97,15,2,74,97,15,2,
104,89,2,15,104,89,2,15,
86,187,1,16,86,187,1,16,
70,188,0,17,189,59,18,0,
190,77,17,1,86,191,1,17,
70,192,0,18,193,59,19,0,
194,77,18,1,86,195,1,18,
70,196,0,19,193,59,20,0,
197,77,19,1,86,198,1,19,
70,196,0,20,199,77,20,1,
86,200,1,20,201,77,21,1,
86,202,1,21,203,77,22,1,
86,204,1,22,205,77,23,1,
86,206,1,23,207,77,24,1,
86,208,1,24,209,77,25,1,
86,210,1,25,211,77,26,1,
86,212,1,26,213,77,27,1,
86,214,1,27,215,77,28,1,
86,216,1,28,217,77,29,1,
86,218,1,29,219,77,30,1,
86,220,1,30,221,77,31,1,
86,222,1,31,223,77,32,1,
86,224,1,32,225,77,33,1,
86,226,1,33,227,77,34,1,
86,228,1,34,229,77,35,1,
86,230,1,35,231,77,36,1,
86,232,1,36,233,77,37,1,
86,234,1,37,235,77,38,1,
86,236,1,38,237,77,39,1,
86,238,1,39,239,77,40,1,
86,240,1,40,241,77,41,1,
86,242,1,41,243,77,42,1,
86,244,1,42,245,77,43,1,
86,246,1,43,247,77,44,1,
86,248,1,44,249,77,45,1,
86,250,1,45,251,77,46,1,
86,252,1,46,253,77,47,1,
86,254,1,47,253,77,48,1,
86,254,1,48,0,0,0,0
}} {}

int Nonstationary::Next(int state, int bit) const {
  return table_[state * 4 + bit];
}

float Nonstationary::InitProbability(int state) const {
  return (table_[state * 4 + 3] + 1.0) /
      (table_[state * 4 + 2] + table_[state * 4 + 3] + 1.0);
}
