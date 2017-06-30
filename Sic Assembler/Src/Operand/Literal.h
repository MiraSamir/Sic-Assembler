#ifndef SICASSEMBLERV2_LITERAL_H
#define SICASSEMBLERV2_LITERAL_H


#include "Operand.h"

class Literal: public Operand {
public:
    Literal(LiteralTable* literalTable);
    bool isLiteral();
    bool isValid();
    int getHexaValue();
    int getByteLength();
    int getOperandAddress(Error* error, int currentLC);
    std::vector<std::string> generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
private:
    LiteralTable* literalTable;

};

#endif //SICASSEMBLERV2_LITERAL_H
