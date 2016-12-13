#include "encoder.h"

Encoder::Encoder(std::ofstream* os, PAQ8L* p) : os_(os), x1_(0),
    x2_(0xffffffff) {
		//this->manager_ = new Manager();
		this->generando = false;
		p_ =  p;
		}

void Encoder::WriteByte(unsigned int byte) {
  os_->put(byte);
}

unsigned int Encoder::Discretize(float p) {
  return 1 + 65534 * p;
}

void Encoder::Encode(int bit) {
  if(!generando)
  
    //printf("%f", p_->Predict());
	this->p = Discretize(p_->Predict());

  const unsigned int xmid = x1_ + ((x2_ - x1_) >> 16) * p +
      (((x2_ - x1_) & 0xffff) * p >> 16);
  if (bit) {
    x2_ = xmid;
  } else {
    x1_ = xmid + 1;
  }
  p_->Perceive(bit, generando);
  /*
  
  bool byte_update = false;
  if (this->manager_->bit_context_ >= 128) byte_update = true;

  this->manager_->Perceive(bit);
  
  if (byte_update) {
    p_->ByteUpdate();
	manager_->bit_context_ = 1;
  }
  */
  while (((x1_^x2_) & 0xff000000) == 0) {
    WriteByte(x2_ >> 24);
    x1_ <<= 8;
    x2_ = (x2_ << 8) + 255;
  }
  X1 = x1_;
  X2 = x2_;
  //xMid = x1_ + ((x2_ - x1_) >> 16) * p + (((x2_ - x1_) & 0xffff) * p >> 16);
  //printf("X1: %u\n", X1);
  //printf("X2: %u\n", X2);
  //printf("Xmid: %u\n", xMid);
  
}

void Encoder::Flush() {
  while (((x1_^x2_) & 0xff000000) == 0) {
    WriteByte(x2_ >> 24);
    x1_ <<= 8;
    x2_ = (x2_ << 8) + 255;
  }
  WriteByte(x2_ >> 24);
}
