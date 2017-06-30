
#include "../Line/LiteralDefinition.h"

#include <iostream>
#include "../Factories/OperandFactory.h"

LiteralDefinition::LiteralDefinition(SymbolTable *symbolTable) : Mnemonic(symbolTable) {
}

void LiteralDefinition::setLiteralTable(LiteralTable *literalTable) {
    this->literalTable = literalTable;
    operandFactory = new OperandFactory(this->literalTable, nullptr);
}

std::string LiteralDefinition::generateObjectcode(SymbolTable *symbolTable,
                                                     int lineAddress, Error* error) {

   Operand* operand = this->operandFactory->getOperandType(this->getFieldStr());
   std::vector<std::string> vec =  operand->generateObjectcode(symbolTable, lineAddress, error);
    return vec[0];
}


bool LiteralDefinition::isLTRDEF(){
    return true;
}


/*

Operand* LiteralDefinition::getOperandType(std::string s) {
    Operand* operand;
    std::string temp = s.substr(1, s.length() - 1);
    if (this->isCharac(temp)) {
        operand->setFieldStr(temp);
        operand->setAbsoluteOperand()
        this->character->setAbsoluteOperand(this->getAbsoluteCharacter(temp));
        return this->character;
    }
    if (this->isHexachar(temp)) {
        this->hexaDecimal->setFieldStr(temp);
        this->hexaDecimal->setAbsoluteOperand(this->getAbsoluteHexa(temp));
        return this->hexaDecimal;
    }
    if (Utility::isInteger(temp)) {
        this->integer->setFieldStr(temp);
        this->integer->setAbsoluteOperand(temp);
        return this->integer;
    }
    this->asteric->setFieldStr(temp);
    this->asteric->setAbsoluteOperand(temp);
    return this->asteric;

}



bool OperandFactory::isHexachar(std::string &s) {
    int size = s.size();
    if (size > 3 && s[1] == '\'' && s[size - 1] == '\'') {
        char c = toupper(s[0]);
        std::string sub = s.substr(2, size - 3);
        if (c == 'X')
            return Utility::isHex(sub);
        else
            return false;
    }
    return false;
}

bool OperandFactory::isCharac(std::string &s) {
    int size = s.size();
    if (size > 3 && s[1] == '\'' && s[size - 1] == '\'') {
        char c = toupper(s[0]);
        std::string sub = s.substr(2, size - 3);
        if (c == 'C')
            return true;
        return false;
    }
    return false;
}



std::string OperandFactory::getAbsoluteCharacter(std::string s) {
    std::string copy = s;
    std::string::iterator end_pos = std::remove(copy.begin(), copy.end(), ' ');
    copy.erase(end_pos, copy.end());
    std::string s1 = "C'";
    std::string s2 = "c'";
    if ((std::equal(s1.begin(), s1.end(), copy.begin()))
        || (std::equal(s2.begin(), s2.end(), copy.begin()))) {
        copy.erase(0, 2);
        copy.erase(copy.size() - 1, 1);
    }
    return copy;
}

std::string OperandFactory::getAbsoluteHexa(std::string s) {
    std::string copy = s;
    std::string::iterator end_pos = std::remove(copy.begin(), copy.end(), ' ');
    copy.erase(end_pos, copy.end());
    std::string s3 = "x'";
    std::string s4 = "X'";
    if ((std::equal(s3.begin(), s3.end(), copy.begin()))
        || (std::equal(s4.begin(), s4.end(), copy.begin()))) {
        copy.erase(0, 2);
        copy.erase(copy.size() - 1, 1);
    }
    return copy;
*/
//}
