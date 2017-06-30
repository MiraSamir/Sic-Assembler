
#ifndef LTORG_H_
#define LTORG_H_

#include "Mnemonic.h"
#include "Directive.h"

class LTORG : public Directive {
public:
    LTORG(SymbolTable* symbolTable,LiteralTable* literalTable);
    int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label);
    bool isLTORG();

};
#endif /* LTORG_H_ */
