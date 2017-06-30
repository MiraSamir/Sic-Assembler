#ifndef SICASSEMBLERV2_EXPRESSION_H
#define SICASSEMBLERV2_EXPRESSION_H


#include <string>
#include "Operand.h"
#include "../Tables/SymbolTable.h"

class Expression : public Operand {
public:
    Expression(SymbolTable* symbolTable);
    bool isExpression();
    bool isValid();
    int getOperandAddress(Error* error, int currentLC) ;
private:
    SymbolTable* symbolTable;
    int value;
    void splitExpression();
    std::vector<std::string> vect;

};


#endif //SICASSEMBLERV2_EXPRESSION_H
