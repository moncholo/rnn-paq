#ifndef DECODER_H
#define DECODER_H

#include <fstream>

#include "../ppm.h"

class Decoder {
 public:
  Decoder(std::ifstream* is, PPM* p);
  int Decode();  // Returns 0 or 1.

 private:
  int ReadByte();
  unsigned int Discretize(float p);

  std::ifstream* is_;
  unsigned int x1_, x2_, x_;
  PPM* p_;
};

#endif
