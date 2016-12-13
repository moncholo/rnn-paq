#ifndef DECODER_H
#define DECODER_H

#include <fstream>

#include "../paq8l.h"

class Decoder {
 public:
  Decoder(std::ifstream* is, PAQ8L* p);
  int Decode();  // Returns 0 or 1.

 private:
  int ReadByte();
  unsigned int Discretize(float p);

  std::ifstream* is_;
  unsigned int x1_, x2_, x_;
  PAQ8L* p_;
};

#endif
