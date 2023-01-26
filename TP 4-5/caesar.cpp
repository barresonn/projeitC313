#include "caesar.h".h "

caesar::caesar() {}
void caesar::encode() { encode(3); }
void caesar::encode(int key) {

  _cipher.clear();

  std::string::iterator it;
  for (it = _plain.begin(); it != _plain.end(); it++) {

    _cipher += ((*it - 'a' + key) % 26 + 'a');
  }
}

void caesar::decode(int key) {
  _cipher.clear();

  std::string::iterator it;
  for (it = _plain.begin(); it != _plain.end(); it++) {

    _cipher += ((*it - 'a' - key) % 26 + 'a');
  }
}
void caesar::decode() { decode(3); }