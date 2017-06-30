
#ifndef SICASSEMBLERV2_WORD_H
#define SICASSEMBLERV2_WORD_H


#include "Mnemonic.h"
#include "Directive.h"

class Word : public Directive{
public:
    Word(SymbolTable* symbolTable);
    int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label);
    bool requireIntOperand();
    bool isWORD();
private:
    int evaluateWordSize(std::string literal);


};


#endif //SICASSEMBLERV2_WORD_H
