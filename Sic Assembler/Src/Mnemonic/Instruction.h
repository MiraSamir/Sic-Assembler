

#ifndef SICASSEMBLERV2_INSTRUCTION_H
#define SICASSEMBLERV2_INSTRUCTION_H

#include "Mnemonic.h"
#include "../Line/Label.h"

class Instruction : public Mnemonic {
public:
    Instruction(SymbolTable* symbolTable);
    virtual int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label);
    virtual bool isRSUB();
    virtual void isOperandRequired(Error* error, Operand* operand);
    virtual bool  requireIntOperand();
    bool isOperation();


};
#endif //SICASSEMBLERV2_INSTRUCTION_H
