//
// Created by me on 5/20/2017.
//

#ifndef SICASSEMBLERV2_HEXADECIMAL_H
#define SICASSEMBLERV2_HEXADECIMAL_H


#include "Operand.h"

class HexaDecimal : public Operand {
public:

    bool isValid();
    bool isDirectiveOperand();
    bool isHexOperand();
    int getByteLength();
    std::vector<std::string> generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
    int getOperandAddress(Error* error, int currentLC) ;
private:
    static const int LIMITSIZE = 14;

};


#endif //SICASSEMBLERV2_HEXADECIMAL_H
