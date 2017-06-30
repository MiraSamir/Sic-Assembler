#ifndef SICASSEMBLERV2_BYTE_H
#define SICASSEMBLERV2_BYTE_H


#include "Mnemonic.h"
#include "Directive.h"

class Byte : public Directive{
public:
    Byte(SymbolTable* symbolTable);
    int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label);
    bool isBYTE();

};


#endif //SICASSEMBLERV2_BYTE_H
