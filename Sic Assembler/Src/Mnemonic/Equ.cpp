
#include "Equ.h"
#include "../ErrorMessages.h"
#include "../Tables/SymbolTable.h"
#include "../Tables/LiteralTable.h"
#include "../Utility.h"
#include <iostream>
#include <algorithm>
Equ::Equ(SymbolTable *symbolTable, LiteralTable * literalTable) :
        Directive(symbolTable) {
    this->literalTable = literalTable;
}

int Equ::evaluateLine(int currentLC, int length, Error *error, Operand *operand,
                      Address *address, Label* label) {   //NO FORWARD REF

    if (label->getFieldStr().empty()) {
        error->addErrorMessage(ErrorMessages::error.find(15)->second);
    } else if (operand->isEmpty()) {
        error->addErrorMessage(ErrorMessages::error.find(6)->second);

    } else {

        address->setAddress(operand->getOperandAddress(error, currentLC));
    }
    return currentLC;
}


bool Equ::isEQU() {
    return true;
}
