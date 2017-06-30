#include <cstdlib>
#include <sstream>
#include "Operand.h"
#include <iostream>

std::string Operand::getAbsoluteOperand() {
	return this->absoluteOperand;
}

void Operand::setAbsoluteOperand(std::string s) {
	this->absoluteOperand = s;
}

void Operand::isIndexed(bool indexed) {
	this->indexed = indexed;
}

bool Operand::isIndexed() {
	return this->indexed;
}

bool Operand::isDirectiveOperand() {
	return false;
}
Operand* Operand::getOperandType() {
	return this->operandType;
}

bool Operand::isEmpty() {
	return false;
}

bool Operand::isIntegerOperand() {
	return false;
}
bool Operand::isAsteric() {
	return false;
}

bool Operand::isHexOperand() {
	return false;
}

bool Operand::isCharOperand() {
	return false;
}

bool Operand::isLiteral() {
	return false;
}

bool Operand::isTargetAddress() {
	return false;
}

bool Operand::isAbsoluteAddress() {
	return false;
}

bool Operand::isExpression() {
	return false;
}

bool Operand::isMultipleWord() {
	return false;
}

bool Operand::isValid() {
	return false;
}
int Operand::getHexaValue() {
	return 0;
}
int Operand::getByteLength() {
	return 0;
}
std::vector<std::string> Operand::getParsedWordOp() {
	return this->parsedWordOp;
}

void Operand::setParsedWordOp(std::vector<std::string> parsed) {
	this->parsedWordOp = parsed;
}

std::vector<std::string> Operand::generateObjectcode(SymbolTable *symbolTable,
		int lineAddress, Error* error) {
	return this->getObjectcode();
}

std::vector<std::string> Operand::getObjectcode() {
	return this->objectCode;
}

int Operand::indexingObcode(int s) {
	s = s ^ 0x8000;
	return s;
}

int Operand::getOperandAddress(Error* error, int currentLC) {
	return 0;
}

std::string Operand::indexingObcode(std::string s) {
	int x = static_cast<int>(strtoul(s.c_str(), NULL, 16));
	x ^= 0x8000;
	std::stringstream stream;
	stream << std::hex << x;
	std::string result(stream.str());
	return result;
	/* std::stringstream stream;
	 stream << std::hex << x;
	 std::string result( stream.str() );
	 return result;*/
}

void Operand::setOperandType(Operand* type) {
	this->operandType = type;
}
void Operand::trimOverflow(std::string &string) {

	if (string.size() > OBCODELENGTH) {
		string.erase(0, abs(string.size() - OBCODELENGTH));
	}
}

bool Operand::isUndefined() {
	return false;
}

bool Operand::isNEG(std::string s) {
	int x = static_cast<int>(strtoul(s.c_str(), NULL, 16));
	return (x < 0);
}
