#ifndef ENCODER_H
#define ENCODER_H

#include <fstream>

#include "../paq8l.h"

class Encoder {
 public:
  Encoder(std::ofstream* os, PAQ8L* p);
  void Encode(int bit);
  void Flush();
  unsigned int X1, X2, p;
  unsigned int Discretize(float p);
  bool generando;
  PAQ8L* p_;

 private:
  void WriteByte(unsigned int byte);
  std::ofstream* os_;
  unsigned int x1_, x2_;

};

#endif
