#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "../Operand/Expression.h"
#include "../Line/Field.h"
#include "../Operand/TargetAddress.h"
#include "../Utility.h"
#include "../Operand/Integer.h"

Expression::Expression(SymbolTable* symbolTable) {
	this->symbolTable = symbolTable;
	this->value = 0;
}
bool Expression::isExpression() {
	return true;
}
bool Expression::isValid() {
	std::stringstream ss;
	std::string token;
	int upperLimit = 0x7fff, lowerLimit = 0, value1 = 0, value2;
	this->splitExpression();
	if (this->symbolTable->count(vect[0]) == 1) {
		value1 = this->symbolTable->find(vect[0])->second;
	} else if (Utility::isInteger(vect[0])) {
		value1 = std::atoi(vect[0].c_str());
	} else {
		return false;
	}
	if (this->symbolTable->count(vect[1]) == 1) {
		value2 = this->symbolTable->find(vect[1])->second;
	} else if (Utility::isInteger(vect[1])) {
		value2 = std::atoi(vect[1].c_str());
	} else {
		return false;
	}
	if (this->getAbsoluteOperand().find("+") != std::string::npos) {
		this->value = value1 + value2;
	} else {
		this->value = value1 - value2;
	}
	if (this->value < lowerLimit || this->value > upperLimit)
		return false;
	return true;
}

int Expression::getOperandAddress(Error* error, int currentLC) {
	return this->value;

}

void Expression::splitExpression() {
	std::stringstream ss;
	std::string s = this->getAbsoluteOperand();
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			this->vect.push_back(ss.str());
			ss.str(std::string());
		} else {
			ss << s[i];
		}
	}
	this->vect.push_back(ss.str());

}
