#include "enigma.h"
#include <iostream>

enigma::enigma(){};
void enigma::encode() { encode(0, 0, 0); }
void enigma::encode(int offset1, int offset2, int offset3) {

  _cipher.clear();
  _intermediary = _plain;

  rotor(offset1, Rotor[0], 1);
  _intermediary = _cipher;
  std::cout << "cipher 1" << _cipher << std::endl;
  rotor(offset2, Rotor[1], 2);
  _intermediary = _cipher;
  std::cout << "cipher 2" << _cipher << std::endl;
  rotor(offset3, Rotor[2], 3);
  _intermediary = _cipher;
  std::cout << "cipher 2" << _cipher << std::endl;
}
void enigma::decode() { decode(0, 0, 0); }
void enigma::decode(int offset1, int offset2, int offset3) {

  rotordecode(offset1, Rotor[2], 3);
  std::cout << "decipher 1" << _plain << std::endl;
  _intermediary = _plain;
  rotordecode(offset1, Rotor[1], 2);
  std::cout << "decipher 2" << _plain << std::endl;
  _intermediary = _plain;
  rotordecode(offset1, Rotor[0], 1);
  std::cout << "decipher 3" << _plain << std::endl;
}

void enigma::rotor(int offset, std::string Rotortype, int level) {
  std::string::iterator at;
  _cipher.clear();
  for (at = _intermediary.begin(); at != _intermediary.end(); at++) {
    _cipher += Rotortype[(*at - 'a' + offset) % 26];

    if (level == 1) {
      offset++;
    } else {
      if (level == 2) {
        if ((at - _intermediary.begin() + 1) % 26 == 0) {
          offset++;
        }
      } else {
        if (level == 3) {
          if ((at - _intermediary.begin() + 1) % 676 == 0) {
            offset++;
          }
        }
      }
    }
  }
}

void enigma::rotordecode(int offset, std::string Rotortype, int level) {
  _plain.clear();
  for (std::string::iterator at = _intermediary.begin();
       at != _intermediary.end(); at++) {

    int testletter = 0;
    while (Rotortype[testletter] != *at) {
      testletter++;
    }
    _plain += (testletter - offset + 26000) % 26 + 'a';

    if (level == 1) {
      offset++;
    } else {
      if (level == 2) {
        if ((at - _intermediary.begin() + 1) % 26 == 0) {
          offset++;
        }
      } else {
        if (level == 3) {
          if ((at - _intermediary.begin() + 1) % 676 == 0) {
            offset++;
          }
        }
      }
    }
  }
}