#ifndef SICASSEMBLERV2_START_H
#define SICASSEMBLERV2_START_H


#include "Mnemonic.h"
#include "Directive.h"

class Start : public Directive {
public:
    Start(SymbolTable* symbolTable);
    bool isSTART();
    int evaluateLine(int currentLC, int length, Error *error, Operand *operand, Address *address, Label* label);
};


#endif //SICASSEMBLERV2_START_H
