#include <cstdlib>
#include "Resb.h"
#include "../ErrorMessages.h"

Resb::Resb(SymbolTable* symbolTable) : Directive(symbolTable) {}


int Resb::evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label *label) {
    if (operand->isIntegerOperand() && !operand->isMultipleWord() && !operand->isNEG(operand->getAbsoluteOperand()) && !operand->isExpression()) {
        address->setAddress(currentLC);
        return currentLC + std::atoi(operand->getAbsoluteOperand().c_str());
    }
    error->addErrorMessage(ErrorMessages::error.find(6)->second);
    address->setAddress(currentLC);
    return currentLC;
}
bool Resb::requireIntOperand(){
    return true;
}

bool Resb::isRESDirective(){
    return true;
}
