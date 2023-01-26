#include "encrypt.h"

class enigma : public encrypt {

public:
  enigma();
  void encode();
  void encode(int offset1, int offset2, int offset3);
  void decode(int offset1, int offset2, int offset3);
  void decode();

private:
  std::string Rotor[3] = {"ekmflgdqvzntowyhxuspaibrcj",
                          "esovpzjayquirhxlnftgkdcmwb",
                          "bdfhjlcprtxvznyeiwgakmusqo"};
  void rotor(int offset, std::string Rotortype, int level);
  void rotordecode(int offset, std::string Rotortype, int level);
  void miror(int Mirortype);
  std::string _intermediary;
};