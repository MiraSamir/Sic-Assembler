
#include <cstdlib>
#include <iostream>
#include "Resw.h"
#include "../ErrorMessages.h"

Resw::Resw(SymbolTable* symbolTable)  : Directive(symbolTable){

}


int Resw::evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label) {

    if (operand->isIntegerOperand() && !operand->isMultipleWord() && !operand->isNEG(operand->getAbsoluteOperand()) && !operand->isExpression()) {
        address->setAddress(currentLC);
        return currentLC + (std::atoi(operand->getAbsoluteOperand().c_str()) * 3);
    }
    error->addErrorMessage(ErrorMessages::error.find(6)->second);
    address->setAddress(currentLC);
    return currentLC;
}
bool Resw::requireIntOperand(){
    return true;
}

bool Resw::isRESDirective() {
    return true;
}
