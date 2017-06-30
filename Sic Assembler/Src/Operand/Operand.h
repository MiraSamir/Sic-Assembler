#ifndef SICASSEMBLERV2_OPERAND_H
#define SICASSEMBLERV2_OPERAND_H

#include "../Line/Field.h"
#include "Error.h"
#include "../Tables/SymbolTable.h"
#include "../Tables/LiteralTable.h"
#include "../ErrorMessages.h"
#include "../Line/Error.h"
#include <algorithm>
#include <vector>

class Operand : public Field {
public:
    virtual bool isValid();
    std::string getAbsoluteOperand();
    virtual void setAbsoluteOperand(std::string s);
    bool isIndexed();
    void isIndexed(bool indexed);
    Operand* getOperandType();
    virtual bool isAsteric();
    virtual bool isDirectiveOperand();
    virtual bool isEmpty();
    virtual bool isIntegerOperand();
    virtual bool isCharOperand();
    virtual bool isHexOperand();
    virtual bool isLiteral();
    virtual bool isTargetAddress();
    virtual bool isAbsoluteAddress();
    virtual bool isExpression();
    virtual bool isMultipleWord();
    virtual std::vector<std::string> getParsedWordOp();
    virtual int getHexaValue();
    virtual int getByteLength();
    virtual int getOperandAddress(Error* error,int currentLC);
    virtual void setParsedWordOp(std::vector<std::string> parsed);
    virtual void setOperandType(Operand* type);
    virtual std::vector<std::string> generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
    std::vector<std::string> getObjectcode();
    void trimOverflow(std::string &s);
    virtual bool isUndefined();
    bool isNEG(std::string string);
private:
    bool indexed;
    std::vector<std::string> parsedWordOp;
    static const int OBCODELENGTH = 6;
protected:
    std::string absoluteOperand;
    Operand* operandType;
    int hexaValue;
    std::vector<std::string> objectCode;
    std::string indexingObcode(std::string s);
    int indexingObcode(int s);

};
#endif //SICASSEMBLERV2_OPERAND_H
