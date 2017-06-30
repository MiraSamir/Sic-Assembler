
#include <string>
#include <iostream>
#include "Instruction.h"
#include "../Mnemonic/Mnemonic.h"
#include "../ErrorMessages.h"
#include "../Line/Label.h"

Instruction::Instruction(SymbolTable* symbolTable)
        : Mnemonic(symbolTable) {
}



bool Instruction::isRSUB() {
    return false;
}

int Instruction::evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label) {
    if(operand->isDirectiveOperand() || operand->isExpression()) {
        error->addErrorMessage(ErrorMessages::error.find(6)->second);
    }
    if(operand->isEmpty() && !isRSUB()) {
        error->addErrorMessage(ErrorMessages::error.find(9)->second);
    }
    isOperandRequired(error, operand);
    address->setAddress(currentLC);
    return currentLC + length;
}


bool Instruction::isOperation() {
    return true;
}

void Instruction::isOperandRequired(Error *error, Operand *operand) {

}
bool Instruction::requireIntOperand(){
    return false;
}





