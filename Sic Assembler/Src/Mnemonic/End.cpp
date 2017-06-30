#include <cstdlib>
#include "End.h"
#include "../ErrorMessages.h"
#include "../Program.h"
#include <iostream>

End::End(SymbolTable* symbolTable, LiteralTable* literalTable) :
		Directive(symbolTable) {
	this->literalTable = literalTable;
}

bool End::isEnd() {
	return true;
}

int End::evaluateLine(int currentLC, int length, Error *error, Operand* operand,
		Address *address, Label* label) {

	address->setAddress(currentLC);

	if (!(operand->isLiteral() || operand->isDirectiveOperand()
			|| operand->isExpression())) {
		if (!this->literalTable->empty()) {
			for (std::map<int,
					std::pair<std::pair<std::string, bool>, std::pair<int, int>>>::iterator it = this->literalTable->begin(); it!=this->literalTable->end(); ++it) {
				if(it->second.second.second == -1) {
					it->second.second.second = currentLC;
					currentLC += it->second.second.first;
				}
			}
		}Program::startingAddress = evaluateStartingAddress(operand);
		Program::programSize = evaluateProgramSize(currentLC);
	}
	else {
		error->addErrorMessage(ErrorMessages::error.find(6)->second);
	}
	return currentLC;
}

int End::evaluateProgramSize(int currentLC) {
	return currentLC - Program::startingLC;
}

int End::evaluateStartingAddress(Operand* operand) {
	if (operand->isEmpty()) {
		return Program::startingLC;
	}
	if (operand->isTargetAddress()) {
		if (this->symbolTable->count(operand->getAbsoluteOperand()) == 0) {
			return Program::startingLC;
		} else {
			return this->symbolTable->find(operand->getAbsoluteOperand())->second;
		}

	} else if (operand->isAbsoluteAddress()) {
		return static_cast<int>(std::strtoul(
				operand->getAbsoluteOperand().c_str(), NULL, 16));
	}
	return 0;
}
