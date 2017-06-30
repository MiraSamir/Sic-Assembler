


#ifndef SICASSEMBLERV2_EQU_H
#define SICASSEMBLERV2_EQU_H

#include "Mnemonic.h"
#include "Directive.h"

class Equ : public Directive {
public:
    Equ(SymbolTable *symbolTable,LiteralTable* literalTable);
    int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label);
    bool isEQU();

};


#endif //SICASSEMBLERV2_EQU_H
