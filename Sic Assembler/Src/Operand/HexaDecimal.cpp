
#include "HexaDecimal.h"
#include "../ErrorMessages.h"


bool HexaDecimal::isValid() {
    return(this->getAbsoluteOperand().size() <= LIMITSIZE);
}


bool HexaDecimal::isDirectiveOperand() {
    return true;
}


bool HexaDecimal::isHexOperand() {
    return true;
}
int HexaDecimal::getOperandAddress(Error* error, int currentLC) {
    error->addErrorMessage(ErrorMessages::error.find(6)->second);
    return currentLC;
}

std::vector<std::string> HexaDecimal::generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error) {
    this->objectCode.clear();
    if(this->isIndexed()) {
        this->objectCode.push_back(this->indexingObcode(this->getAbsoluteOperand()));
    } else {
        this->objectCode.push_back(this->getAbsoluteOperand());
    }
    return this->objectCode;
}
int HexaDecimal::getByteLength(){
    return this->getAbsoluteOperand().size() /2;
}
