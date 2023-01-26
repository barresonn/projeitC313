#include "encrypt.h"

class caesarmod : public encrypt {

public:
  caesarmod();
  void encode();
  void encode(int key);
  void decode();
  void decode(int key);
};