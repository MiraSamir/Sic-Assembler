
#ifndef SICASSEMBLERV2_END_H
#define SICASSEMBLERV2_END_H


#include "Mnemonic.h"
#include "Directive.h"

class End : public Directive {
public:
    End(SymbolTable* symbolTable,LiteralTable* literalTable);
    bool isEnd();
    int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label *label);
    int evaluateStartingAddress(Operand* operand);
    int evaluateProgramSize(int currentLC);


};


#endif //SICASSEMBLERV2_END_H
