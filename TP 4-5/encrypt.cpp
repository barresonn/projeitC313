#include "encrypt.h"
#include <fstream>
#include <iostream>

encrypt::encrypt() : _plain("texte"), _cipher("texte") {}

std::string encrypt::getplain() { std::cout << _plain << std::endl; }

std::string encrypt::getcypher() { std::cout << _plain << std::endl; }

void encrypt::read() {

  std::string line;
  std::string texte;
  std::ifstream myfile("readfile");
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      texte += line;
    }
    _plain = texte;
    myfile.close();
  } else
    std::cout << "Unable to open file";
}

void encrypt::write() {

  std::ofstream myfile("cypher.txt");
  if (myfile.is_open()) {
    myfile << _cipher;
    myfile.close();
  } else
    std::cout << "Unable to open file";
}