#include <cstdlib>
#include <iostream>
#include "AbsoluteAddress.h"
#include "../Line/Field.h"
#include "../ErrorMessages.h"
#include <algorithm>
bool AbsoluteAddress::isValid() {
	int operand_code = static_cast<int>(strtoul(
			this->getAbsoluteOperand().c_str(), NULL, 16));
	return (operand_code <= LIMIT);

}

bool AbsoluteAddress::isAbsoluteAddress() {
	return true;
}

int AbsoluteAddress::getOperandAddress(Error* error, int currentLC) {
	int x = static_cast<int>(strtoul(this->getFieldStr().c_str(), NULL, 16));

	return x;
}
std::vector<std::string> AbsoluteAddress::generateObjectcode(
		SymbolTable *symbolTable, int lineAddress, Error* error) {
	this->objectCode.clear();
	if (this->isIndexed()) {
		//    this->getAbsoluteOperand().substr(0,2);
		this->objectCode.push_back(
				this->indexingObcode(this->getAbsoluteOperand()));
	} else {
		this->objectCode.push_back(this->getAbsoluteOperand());
	}

	return this->objectCode;
}
