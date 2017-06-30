#include "Byte.h"
#include "../ErrorMessages.h"
#include "../Line/Label.h"


int Byte::evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label) {
    if(operand->isDirectiveOperand() && (operand->isCharOperand() || operand->isHexOperand())) {
        address->setAddress(currentLC);
        if(operand->isHexOperand()) {
            int hexaSize = operand->getAbsoluteOperand().size();
            if (hexaSize % 2 == 0)
                return currentLC + (operand->getAbsoluteOperand().size() / 2);
        }else {
            return currentLC + (operand->getAbsoluteOperand().size());
        }
    }
    error->addErrorMessage(ErrorMessages::error.find(6)->second);
    address->setAddress(currentLC);
    return currentLC;

}

Byte::Byte(SymbolTable* symbolTable) : Directive(symbolTable) {}

bool Byte::isBYTE() {
    return true;
}

