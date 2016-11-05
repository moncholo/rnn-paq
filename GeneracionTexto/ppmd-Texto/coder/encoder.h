#ifndef ENCODER_H
#define ENCODER_H

#include <fstream>

#include "../ppm.h"
#include "../manager.h"

class Encoder {
 public:
  Encoder(std::ofstream* os, PPM* p);
  void Encode(int bit);
  void Flush();
  unsigned int X1, X2, p;
  unsigned int Discretize(float p);
  bool generando;
  PPM* p_;
  Manager* manager_;

 private:
  void WriteByte(unsigned int byte);
  std::ofstream* os_;
  unsigned int x1_, x2_;

};

#endif
