
#ifndef SICASSEMBLERV2_INTEGER_H
#define SICASSEMBLERV2_INTEGER_H


#include "Operand.h"

class Integer : public Operand {
public:

    bool isValid();
    bool isDirectiveOperand();
    bool isIntegerOperand();
    bool isMultipleWord();
    int getByteLength();
    void setAbsoluteOperand(std::string s);
    std::vector<std::string> generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
    int getOperandAddress(Error* error, int currentLC);

private:
    bool isWithinRange();
    static const int POSLIMITSIZE = 8388607;
    static const int NEGLIMITSIZE = -8388608;
    std::vector<std::string> parseWordOp(std::string s);


};


#endif //SICASSEMBLERV2_INTEGER_H
