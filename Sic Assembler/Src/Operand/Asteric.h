
#ifndef SICASSEMBLERV2_ASTERIC_H
#define SICASSEMBLERV2_ASTERIC_H


#include "Operand.h"

class Asteric : public Operand {
public:
    bool isAsteric();
    bool isValid();
    std::vector<std::string> generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
    int getOperandAddress(Error* error,int currentLC);
};


#endif //SICASSEMBLERV2_ASTERIC_H
