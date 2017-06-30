


#ifndef SICASSEMBLERV2_TARGETADDRESS_H
#define SICASSEMBLERV2_TARGETADDRESS_H


#include "Operand.h"

class TargetAddress : public Operand {
public:
    TargetAddress(SymbolTable *symbolTable);
    bool isTargetAddress();
    bool isValid();
    std::vector<std::string> generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
    int getOperandAddress(Error* error, int currentLC);
private:
    SymbolTable* symbolTable;

};


#endif //SICASSEMBLERV2_TARGETADDRESS_H
