


#ifndef SICASSEMBLERV2_EMPTYOPERAND_H
#define SICASSEMBLERV2_EMPTYOPERAND_H


#include "Operand.h"

class EmptyOperand : public Operand {
public:

    bool isValid();
    bool isEmpty();
    std::vector<std::string> generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
    int getOperandAddress(Error* error,int currentLC);
};


#endif //SICASSEMBLERV2_EMPTYOPERAND_H
