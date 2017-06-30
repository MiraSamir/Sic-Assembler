
#include <string>
#include <sstream>
#include <iostream>
#include "TargetAddress.h"
#include "../Line/Field.h"
#include "../Utility.h"
#include "../ErrorMessages.h"
#include "../Line/Error.h"
#include <algorithm>

TargetAddress::TargetAddress(SymbolTable *symbolTable){
    this->symbolTable = symbolTable;
}
bool TargetAddress::isTargetAddress() {
    return true;
}

bool TargetAddress::isValid() {
    return true;
}

std::vector<std::string> TargetAddress::generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error *error) {
    this->objectCode.clear();
    std::map<std::string, int>::iterator it;


    if (symbolTable->count(Utility::to_upper(this->getAbsoluteOperand())) != 0) {
        it = symbolTable->find(Utility::to_upper(this->getAbsoluteOperand()));
        std::stringstream ss;
        ss << std::hex << it->second; // int decimal_value
        std::string s_1(ss.str());
        if(this->isIndexed()) {
            s_1 = this->indexingObcode(s_1);
        }
        this->objectCode.push_back(Utility::to_upper(s_1));
    } else {
        error->addErrorMessage(ErrorMessages::error.find(13)->second);
    }
    return this->objectCode;
}
int TargetAddress::getOperandAddress(Error* error, int currentLC) {
    std::string copy = Utility::to_upper(this->getAbsoluteOperand());
    if (this->symbolTable->count(copy) == 0) {
        error->addErrorMessage(ErrorMessages::error.find(6)->second);
    } else {
        currentLC = this->symbolTable->find(copy)->second;
    }
    return currentLC;
}
