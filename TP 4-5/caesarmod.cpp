#include "caesarmod.h"

caesarmod::caesarmod() {}
void caesarmod::encode() { encode(3); }
void caesarmod::encode(int key) {

  _cipher.clear();

  std::string::iterator it;
  for (it = _plain.begin(); it != _plain.end(); it++) {

    _cipher += ((*it - '!' + key) % 93 + '!');
  }
}
void caesarmod::decode() { decode(3); }
void caesarmod::decode(int key) {

  _cipher.clear();

  std::string::iterator it;
  for (it = _plain.begin(); it != _plain.end(); it++) {

    _cipher += ((*it - '!' - key) % 93 + '!');
  }
}