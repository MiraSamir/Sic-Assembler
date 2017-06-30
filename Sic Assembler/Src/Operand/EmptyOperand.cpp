#include "EmptyOperand.h"
#include "../ErrorMessages.h"

bool EmptyOperand::isValid() {
    return true;
}

bool EmptyOperand::isEmpty() {
    return true;
}

std::vector<std::string> EmptyOperand::generateObjectcode(
        SymbolTable *symbolTable, int lineAddress, Error* error) {
    this->objectCode.clear();
    this->objectCode.push_back("");
    return this->objectCode;
}
int EmptyOperand::getOperandAddress(Error* error, int currentLC) {
    error->addErrorMessage(ErrorMessages::error.find(6)->second);
    return currentLC;
}
