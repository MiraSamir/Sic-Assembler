

#ifndef SICASSEMBLERV2_UNDEFINEDFIELD_H
#define SICASSEMBLERV2_UNDEFINEDFIELD_H


#include "../Mnemonic/Mnemonic.h"

class UndefinedField : public Mnemonic, public Operand {
public:
    UndefinedField(SymbolTable *symbolTable);
    UndefinedField();
    bool isUndefined();



};


#endif //SICASSEMBLERV2_UNDEFINEDFIELD_H
