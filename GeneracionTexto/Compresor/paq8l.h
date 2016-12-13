#ifndef PAQ8L_H
#define PAQ8L_H

#include <vector>

class PAQ8L {
 public:
  PAQ8L(int memory);
  float Predict();
  void Perceive(int bit);
  void ByteUpdate() {};
  const std::vector<float>& ModelPredictions();
};

#endif
