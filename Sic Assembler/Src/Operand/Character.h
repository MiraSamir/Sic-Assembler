

#ifndef SICASSEMBLERV2_CHARACTER_H
#define SICASSEMBLERV2_CHARACTER_H


#include "Operand.h"

class Character : public Operand {
public:

    bool isValid();
    bool isDirectiveOperand();
    bool isCharOperand();
    int getByteLength();
    std::vector<std::string> generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
    int getOperandAddress(Error* error, int currentLC);
private:
    static const int LIMITSIZE = 15;

};


#endif //SICASSEMBLERV2_CHARACTER_H
