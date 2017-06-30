
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iostream>
#include "Word.h"
#include "../Utility.h"
#include "../ErrorMessages.h"

Word::Word(SymbolTable* symbolTable) : Directive(symbolTable) {}

int Word::evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label* label) {
    if(operand->isIntegerOperand()) {
        address->setAddress(currentLC);
        return currentLC + this->evaluateWordSize(operand->getAbsoluteOperand());
    } else {
        error->addErrorMessage(ErrorMessages::error.find(6)->second);
        address->setAddress(currentLC);
        return currentLC + 3;
    }
}


int Word::evaluateWordSize(std::string literal) {
    std::istringstream ss(literal);
    std::string token;
    int counter = 0;
    while (std::getline(ss, token, ',')) {
        if (!Utility::isInteger(token))
            return 0;
        else
            counter++;
    }
    if (std::count(literal.begin(), literal.end(), ',') >= counter)
        return 0;
    return (3 * counter);
}
bool Word::requireIntOperand(){
    return true;
}

bool Word::isWORD() {
    return true;
}
