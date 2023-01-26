#include "enigma.h"
#include <iostream>

int main() {
  enigma test;

  test.read();
  test.encode();
  test.write();
  test.decode();
  test.write();
}