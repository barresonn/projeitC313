#include "encrypt.h"

class vigenere : public encrypt {

public:
  vigenere();
  void encode();
  void encode(std::string key);
  void decode();
  void decode(std::string key);
};