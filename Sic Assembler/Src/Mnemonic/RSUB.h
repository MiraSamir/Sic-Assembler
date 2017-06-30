#ifndef SICASSEMBLERV2_RSUB_H
#define SICASSEMBLERV2_RSUB_H


#include "Instruction.h"

class RSUB : public Instruction{
public:
    RSUB(SymbolTable* symbolTable);
    bool isRSUB();
    void isOperandRequired(Error* error, Operand* operand);


};


#endif //SICASSEMBLERV2_RSUB_H
