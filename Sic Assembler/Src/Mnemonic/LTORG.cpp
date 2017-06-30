#include "LTORG.h"
#include "../ErrorMessages.h"
#include <iostream>

LTORG::LTORG(SymbolTable* symbolTable, LiteralTable* literalTable) :
		Directive(symbolTable) {
	this->literalTable = literalTable;
}

bool LTORG::isLTORG() {
	return true;
}
int LTORG::evaluateLine(int currentLC, int length, Error *error,
		Operand *operand, Address *address, Label* label) {
	if (!operand->isEmpty()) {
		error->addErrorMessage(ErrorMessages::error.find(6)->second);
	} else {
		address->setAddress(currentLC);
		if (!this->literalTable->empty()) {
			for (std::map<int,
					std::pair<std::pair<std::string, bool>, std::pair<int, int>>>::iterator it = this->literalTable->begin(); it!=this->literalTable->end(); it++) {
				if(it->second.second.second == -1) {
					it->second.second.second = currentLC;
					currentLC += it->second.second.first;
				}
			}
		}
	}
	return currentLC;
}
