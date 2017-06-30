#ifndef SICASSEMBLERV2_ORG_H
#define SICASSEMBLERV2_ORG_H


#include "Mnemonic.h"
#include "Directive.h"
#include "../ErrorMessages.h"
#include "../Utility.h"

class Org : public Directive{
public:
    Org(SymbolTable* symbolTable,LiteralTable* literalTable);
    int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label);
    bool isORG();
private:
    int prevLC = -1;
};


#endif //SICASSEMBLERV2_ORG_H
