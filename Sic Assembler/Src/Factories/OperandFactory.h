#ifndef SICASSEMBLERV2_OPERANDFACTORY_H
#define SICASSEMBLERV2_OPERANDFACTORY_H


#include <string>
#include "../Operand/Operand.h"
#include <iostream>
#include <algorithm>

class OperandFactory {
public:
    OperandFactory(LiteralTable* literalTabel,SymbolTable* symbolTable);
    Operand* create(std::string s);
    void setDirectiveMood(bool directiveMood) ;
    Operand* getOperandType(std::string s);
private:
    Operand* targetAddress;
    Operand* absoluteAddress;
    Operand* emptyOperand;
    Operand* literal;
    Operand* expression;
    Operand* integer;
    Operand* character;
    Operand* hexaDecimal;
    Operand* asteric;
    Operand* undefined;
    std::vector<std::string> expressionOperands;
    std::string operation;
    bool isdirectiveMood;
    bool isLabel(std::string s);
    bool isAbsoluteAdd(std::string s);
    bool handleMultipleWords(std::string &s);
    bool isHexachar(std::string &s);
    bool isCharac(std::string &s);
    bool isIndexed(std::string &value);
    bool isLiteral(std::string s);
    std::string getAbsoluteCharacter(std::string s);
    std::string getAbsoluteHexa(std::string s);
    std::string getAbsoluteLiteral(std::string s);
    std::string getAbsoluteExpression();
    bool isExpression(std::string s);


};


#endif //SICASSEMBLERV2_OPERANDFACTORY_H
