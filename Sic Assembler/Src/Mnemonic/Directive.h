#ifndef SICASSEMBLERV2_DIRECTIVE_H
#define SICASSEMBLERV2_DIRECTIVE_H
#include <vector>
#include <string>
#include "Mnemonic.h"
#include "../Line/Label.h"

class Directive: public Mnemonic{
public:
    Directive(SymbolTable* symbolTable);
    virtual bool isSTART();
    virtual bool isEnd();
    virtual bool isLTORG();
    virtual bool requireIntOperand();
    virtual int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label *label);
    bool isDirective();
    bool isRESDirective();

protected:
    LiteralTable* literalTable;

};



#endif //SICASSEMBLERV2_DIRECTIVE_H
