#include "Basicencrypt.h"

Basicencrypt::Basicencrypt() {}

void Basicencrypt::encode() { _cipher = _plain; }
void Basicencrypt::decode() { _plain = _cipher; }