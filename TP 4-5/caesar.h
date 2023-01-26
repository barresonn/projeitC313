#include "encrypt.h"

class caesar : public encrypt {

public:
  caesar();
  void encode();
  void encode(int key);
  void decode();
  void decode(int key);
};