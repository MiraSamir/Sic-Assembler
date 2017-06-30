#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iostream>
#include "Integer.h"
#include "../Utility.h"
#include "../ErrorMessages.h"

bool Integer::isValid() {
	std::istringstream ss(this->getAbsoluteOperand());
	std::string token;
	int counter = 0;
	while (std::getline(ss, token, ',')) {
		if (!isWithinRange()) {
			return false;
		} else
			counter++;
	}
	return true;
}

bool Integer::isDirectiveOperand() {
	return true;
}

bool Integer::isIntegerOperand() {
	return true;
}

bool Integer::isMultipleWord() {
	return (this->getAbsoluteOperand().find(",") != std::string::npos);
}

bool Integer::isWithinRange() {
	int value = std::atoi(this->getAbsoluteOperand().c_str());
	return (value <= POSLIMITSIZE && value >= NEGLIMITSIZE);
}

int Integer::getByteLength() {
	if (!isMultipleWord())
		return 3;
	else
		//mo2katan
		return 0;
}
std::vector<std::string> Integer::parseWordOp(std::string operand) {
	std::vector<std::string> wordParsed;
	std::string::iterator end_pos = std::remove(operand.begin(), operand.end(),
			' ');
	operand.erase(end_pos, operand.end());
	std::stringstream test(operand);
	std::string segment;
	std::vector<std::string> seglist;

	while (std::getline(test, segment, ',')) {
		wordParsed.push_back(segment);
	}
	return wordParsed;
}

std::vector<std::string> Integer::generateObjectcode(SymbolTable *symbolTable,
		int lineAddress, Error* error) {
	this->objectCode.clear();
	std::vector<std::string> hex;
	std::string string;
	int x;
	for (unsigned int i = 0; i < this->getParsedWordOp().size(); i++) {

		x = static_cast<int>(strtoul(this->getParsedWordOp()[i].c_str(), NULL,
				16));
		std::stringstream ss;
		ss << std::hex << x;  // int decimal_value
		string = Utility::to_upper(ss.str());
		this->trimOverflow(string);

		hex.push_back(string);
	}
	return hex;
}
int Integer::getOperandAddress(Error* error, int currentLC) {
	error->addErrorMessage(ErrorMessages::error.find(6)->second);
	return currentLC;
}
void Integer::setAbsoluteOperand(std::string s) {
	this->absoluteOperand = s;
	if (this->isValid()) {
		this->setParsedWordOp(this->parseWordOp(s));
	}
}
