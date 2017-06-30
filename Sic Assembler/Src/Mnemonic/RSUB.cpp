#include "RSUB.h"
#include "Instruction.h"
#include "../ErrorMessages.h"


RSUB::RSUB(SymbolTable* symbolTable) :
        Instruction(symbolTable) {

}




bool RSUB::isRSUB() {
    return true;
}


void RSUB::isOperandRequired(Error *error, Operand* operand) {
    if(!operand->isEmpty()) {
        error->addErrorMessage(ErrorMessages::error.find(10)->second);
    }
}
