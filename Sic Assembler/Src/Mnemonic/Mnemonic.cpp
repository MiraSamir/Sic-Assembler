#include <ios>
#include <sstream>
#include <iostream>
#include "../Mnemonic/Mnemonic.h"
#include "../Utility.h"

Mnemonic::Mnemonic(SymbolTable *symbolTable) {
    this->symbolTable = symbolTable;

}
bool Mnemonic::isLTORG() {
    return false;
}
bool Mnemonic::isDirective() {
    return false;
}

bool Mnemonic::isOperation() {
    return false;
}

bool Mnemonic::isSTART() {
    return false;
}

bool Mnemonic::isEnd() {
    return false;
}
std::string Mnemonic::getFieldStr() {
    return Field::getFieldStr();
}

void Mnemonic::setFieldStr(std::string s) {
    Field::setFieldStr(s);
}

int Mnemonic::evaluateStartingAddress(Operand* operand) {
    return 0;
}
int Mnemonic::evaluateProgramSize(int currentLC) {
    return 0;
}

int Mnemonic::evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label) {
    return 0;
}
bool Mnemonic::requireIntOperand() {
    return false;
}

bool Mnemonic::isWORD() {
    return false;
}

bool Mnemonic::isBYTE() {
    return false;
}

bool Mnemonic::isRESDirective() {
    return false;
}

std::string Mnemonic::generateObjectcode(OpTable *optable) {
    if (!this->isDirective()) {
        std::unordered_map<std::string, std::pair<int, int>>::iterator it_1 =
                optable->find(Utility::to_upper(this->getFieldStr()));
        int mnemonic_code = it_1->second.first;
        std::stringstream ss;
        ss << std::hex << mnemonic_code; // int decimal_value
        std::string s_1(ss.str());
        return Utility::to_upper(s_1);
    } else {
        return "";
    }
}

bool Mnemonic::isUndefined() {
    return false;
}


///////////////////////////////////////////////////////////////////////////////////////
void Mnemonic::setLiteralTable(LiteralTable *literalTable) {

}


std::string Mnemonic::generateObjectcode(SymbolTable *symbolTable,
                                                               int lineAddress, Error* error) {
    return "";
}

bool Mnemonic::isLTRDEF() {
    return false;
}


////////////////////////////////////////////////////////////////////////////////////////

bool Mnemonic::isEQU() {
    return false;
}
bool Mnemonic::isORG() {
    return false;
}


///////////////////////////////////////////////////////////////////////////////////////////////
