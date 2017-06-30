
#ifndef SICASSEMBLERV2_LITERALDEFINITION_H
#define SICASSEMBLERV2_LITERALDEFINITION_H


#include "../Mnemonic/Mnemonic.h"
#include "../Operand/Literal.h"
#include "../Factories/OperandFactory.h"

class LiteralDefinition : public Mnemonic {
public:
    LiteralDefinition(SymbolTable *symbolTable);
    void setLiteralTable(LiteralTable* literalTable);
    std::string generateObjectcode(SymbolTable *symbolTable,
                                                         int lineAddress, Error* error);
    bool isLTRDEF();
private:
    LiteralTable* literalTable;
    OperandFactory* operandFactory;

};


#endif //SICASSEMBLERV2_LITERALDEFINITION_H
