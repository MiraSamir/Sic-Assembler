#include <cstdlib>
#include <sstream>
#include "Literal.h"
#include "iostream"
#include "../ErrorMessages.h"
#include "../Factories/OperandFactory.h"
#include "../Utility.h"

Literal::Literal(LiteralTable* literalTable) {
    this->literalTable = literalTable;
}

bool Literal::isLiteral() {
    return true;
}

bool Literal::isValid() {
    return this->operandType->isValid();
}
int Literal::getHexaValue() {
    std::string temp = this->operandType->generateObjectcode(NULL, NULL, NULL)[0];
    return static_cast<int>(std::strtoul(temp.c_str(), NULL, 16));
}
int Literal::getByteLength() {
    return this->operandType->getByteLength();
}
int Literal::getOperandAddress(Error* error, int currentLC) {
    int hexaValue = this->getHexaValue();
    if(this->getOperandType()->isAsteric())
        return currentLC;
    else if(this->literalTable->count(hexaValue) == 0  || this->literalTable->find(hexaValue)->second.second.second == -1 ){
        error->addErrorMessage(ErrorMessages::error.find(6)->second);
    } else{
        currentLC = this->literalTable->find(hexaValue)->second.second.second;
    }
    return currentLC;
}
std::vector<std::string> Literal::generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error){
    OperandFactory* operandFactory = new OperandFactory(this->literalTable, symbolTable);
    Operand* operand = operandFactory->getOperandType(this->getFieldStr());

    if(operand->isAsteric()) {
        return operand->generateObjectcode(symbolTable, lineAddress, error);
    } else {
        std::string str = operand->generateObjectcode(symbolTable, lineAddress, error)[0];
        int x = static_cast<int>(strtoul(str.c_str(), NULL,
                                         16));


        int add = this->literalTable->find(x)->second.second.second;
        std::stringstream ss;
        ss << std::hex << add;  // int decimal_value
        std::string string =  Utility::to_upper(ss.str());
        this->trimOverflow(string);
        std::vector<std::string> vec;
        vec.push_back(string);
        return vec;
    }
}
