#include "vigenere.h"
#include <string>

vigenere::vigenere() {}
void vigenere::encode() { vigenere::encode("turing"); }
void vigenere::encode(std::string key) {

  _cipher.clear();

  std::string::iterator it;
  std::string::iterator at;

  at = key.begin();
  for (it = _plain.begin(); it != _plain.end(); it++) {
    _cipher += ((*it - '!' + ((*at) - 'a') % 26) % 93 + '!');
    if (at != key.end() - 1) {
      at++;
    } else {
      at = key.begin();
    }
  }
}
void vigenere::decode(std::string key) {

  _cipher.clear();

  std::string::iterator it;
  std::string::iterator at;

  at = key.begin();
  for (it = _plain.begin(); it != _plain.end(); it++) {
    _cipher += ((*it - '!' - ((*at) - 'a' + 26000) % 26) % 93 + '!');
    if (at != key.end()) {
      at++;
    } else {
      at = key.begin();
    }
  }
}

void vigenere::decode() { vigenere::decode("turing"); }
