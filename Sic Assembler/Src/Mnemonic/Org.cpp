#include "Org.h"
#include "../Tables/SymbolTable.h"
#include "../Tables/LiteralTable.h"
#include <iostream>
#include <algorithm>
Org::Org(SymbolTable* symbolTable, LiteralTable* literalTable) :
        Directive(symbolTable) {
    this->prevLC = -1;
    this->literalTable = literalTable;
}

int Org::evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label){
    if (!label->getFieldStr().empty()) {
        error->addErrorMessage(ErrorMessages::error.find(14)->second);
    } else if (operand->isEmpty()) {
        if (this->prevLC == -1) {
            address->setAddress(currentLC);
            return currentLC;
        } else {
            currentLC = this->prevLC;
            this->prevLC = -1;
        }
    } else {
        this->prevLC = currentLC;
        currentLC = operand->getOperandAddress(error, currentLC);

    }
    address->setAddress(currentLC);
    return currentLC;

}


bool Org::isORG() {
    return true;
}
