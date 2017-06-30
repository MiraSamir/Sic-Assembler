//
// Created by me on 5/19/2017.
//

#ifndef SICASSEMBLERV2_RESB_H
#define SICASSEMBLERV2_RESB_H


#include "Mnemonic.h"
#include "Directive.h"

class Resb : public Directive{
public:
    Resb(SymbolTable* symbolTable);
    int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label *label);
    bool requireIntOperand();
    bool isRESDirective();


};


#endif //SICASSEMBLERV2_RESB_H
