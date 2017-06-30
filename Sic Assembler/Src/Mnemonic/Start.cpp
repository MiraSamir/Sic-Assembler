#include <cstdlib>
#include <iostream>
#include "Start.h"
#include "../Program.h"
#include "../ErrorMessages.h"

bool Start::isSTART() {
	return true;
}

Start::Start(SymbolTable* symbolTable) :
		Directive(symbolTable) {
}

int Start::evaluateLine(int currentLC, int length, Error *error,
		Operand* operand, Address *address, Label* label) {
	if (operand->isAbsoluteAddress()) {
		currentLC = static_cast<int>(std::strtoul(
				operand->getAbsoluteOperand().c_str(), NULL, 16));
		address->setAddress(currentLC);
		Program::startingLC = currentLC;
		Program::programName = label->getFieldStr();
		return currentLC;
	} else {
		error->addErrorMessage(ErrorMessages::error.find(6)->second);
		address->setAddress(currentLC);
		return currentLC;
	}

}
