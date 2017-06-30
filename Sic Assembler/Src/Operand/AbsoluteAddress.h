#ifndef SICASSEMBLERV2_ABSOLUTEADDRESS_H
#define SICASSEMBLERV2_ABSOLUTEADDRESS_H

#include <string>
#include "Operand.h"

class AbsoluteAddress: public Operand {
public:

    bool isValid();
    bool isAbsoluteAddress();
    std::vector<std::string> generateObjectcode(SymbolTable *symbolTable,
                                                int lineAddress, Error* error);
    int getOperandAddress(Error* error, int currentLC);

private:
    static const int LIMIT = 0x7FFFF;
};

#endif //SICASSEMBLERV2_ABSOLUTEADDRESS_H
