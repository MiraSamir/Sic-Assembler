#include <sstream>
#include <algorithm>
#include <iostream>
#include "OperandFactory.h"
#include "../Operand/Asteric.h"
#include "../Operand/TargetAddress.h"
#include "../Operand/AbsoluteAddress.h"
#include "../Utility.h"
#include "../Operand/Integer.h"
#include "../Operand/HexaDecimal.h"
#include "../Operand/Character.h"
#include "../Operand/EmptyOperand.h"
#include "../Operand/Expression.h"
#include "../Operand/Literal.h"
#include "../Line/UndefinedField.h"

OperandFactory::OperandFactory(LiteralTable* literalTable,
		SymbolTable* symbolTable) {
	this->isdirectiveMood = false;
	this->targetAddress = new TargetAddress(symbolTable);
	this->absoluteAddress = new AbsoluteAddress();
	this->character = new Character();
	this->integer = new Integer();
	this->hexaDecimal = new HexaDecimal();
	this->literal = new Literal(literalTable);
	this->asteric = new Asteric();
	this->emptyOperand = new EmptyOperand();
	this->undefined = new UndefinedField();
	this->expression = new Expression(symbolTable);
}
Operand* OperandFactory::create(std::string s) {
	std::string copy = s;
	bool isIndexed = this->isIndexed(copy);
	Operand *operand;
	if (copy.compare("*") == 0) {
		operand = this->asteric;
	} else if (isAbsoluteAdd(s) && !this->isdirectiveMood) {
		operand = this->absoluteAddress;
		// copy.erase(0,2);
	} else if (handleMultipleWords(s)) {
		operand = this->integer;
	} else if (isHexachar(s)) {
		operand = this->hexaDecimal;
		copy = this->getAbsoluteHexa(copy);
	} else if (isCharac(s)) {
		operand = this->character;
		copy = this->getAbsoluteCharacter(copy);
	} else if (isLiteral(s)) {
		operand = this->literal;
		copy = this->getAbsoluteLiteral(copy);
		operand->setOperandType(this->getOperandType(s));
	} else if (isExpression(s)) {
		operand = this->expression;
		copy = this->getAbsoluteExpression();
	} else if (isLabel(s)) {
		operand = this->targetAddress;
	} else if (s.size() == 0) {
		operand = this->emptyOperand;
	} else {
		operand = this->undefined;
	}
	operand->setFieldStr(s);
	operand->isIndexed(isIndexed);
	operand->setAbsoluteOperand(copy);
	return operand;
}

void OperandFactory::setDirectiveMood(bool directiveMood) {
	this->isdirectiveMood = directiveMood;
}
std::string OperandFactory::getAbsoluteExpression() {
	std::stringstream ss;
	Utility::eraseTrailingSpace(this->expressionOperands[0]);
	Utility::eraseLeadingSpace(this->expressionOperands[0]);
	Utility::eraseTrailingSpace(this->expressionOperands[1]);
	Utility::eraseLeadingSpace(this->expressionOperands[1]);
	ss << this->expressionOperands[0] << this->operation
			<< this->expressionOperands[1];
	return ss.str();
}

Operand* OperandFactory::getOperandType(std::string s) {
	std::string temp = s.substr(1, s.length() - 1);
	if (this->isCharac(temp)) {
		this->character->setFieldStr(temp);
		this->character->setAbsoluteOperand(this->getAbsoluteCharacter(temp));
		return this->character;
	}
	if (this->isHexachar(temp)) {
		this->hexaDecimal->setFieldStr(temp);
		this->hexaDecimal->setAbsoluteOperand(this->getAbsoluteHexa(temp));
		return this->hexaDecimal;
	}
	if (Utility::isInteger(temp)) {
		this->integer->setFieldStr(temp);
		this->integer->setAbsoluteOperand(temp);
		return this->integer;
	}
	this->asteric->setFieldStr(temp);
	this->asteric->setAbsoluteOperand(temp);
	return this->asteric;

}

bool OperandFactory::isLiteral(std::string s) {
	if (s.length() > 1 && s[0] == '=') {
		std::string temp = s.substr(1, s.length() - 1);
		return (temp == "*" || this->isCharac(temp) || this->isHexachar(temp)
				|| Utility::isInteger(temp));

	}
	return false;
}

bool OperandFactory::isLabel(std::string s) {
	char ch = s[0];
	if (((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))) {
		return true;
	}
	return false;
}

bool OperandFactory::isAbsoluteAdd(std::string s) {
	if ((s[0] != '0' && (s[1] != 'x' || s[1] != 'X'))
			&& (s[0] < '0' || s[0] > '9'))
		return false;
	if (s[s.length() - 2] == ','
			&& (s[s.length() - 1] == 'x' || (s[s.length() - 1] == 'X'))) {
		s = s.substr(0, s.length() - 2);
	}
	for (size_t i = 1; i < s.size(); i++) {
		char current = s[i];
		if ((current >= '0' && current <= '9')
				|| (current >= 'A' && current <= 'F')
				|| (current >= 'a' && current <= 'f')
				|| (i == 1 && (s[i] == 'x' || s[i] == 'X')))
			continue;
		return false;
	}
	return true;
}

bool OperandFactory::handleMultipleWords(std::string &s) {
	std::istringstream ss(s);
	std::string token;
	int counter = 0;
	while (std::getline(ss, token, ',')) {
		if (!Utility::isInteger(token))
			return false;
		counter++;
	}
	if (counter == 0)
		return Utility::isInteger(s);
	if (std::count(s.begin(), s.end(), ',') > counter)
		return false;
	return true;
}

bool OperandFactory::isHexachar(std::string &s) {
	int size = s.size();
	if (size > 3 && s[1] == '\'' && s[size - 1] == '\'') {
		char c = toupper(s[0]);
		std::string sub = s.substr(2, size - 3);
		if (c == 'X')
			return Utility::isHex(sub);
		else
			return false;
	}
	return false;
}
bool OperandFactory::isExpression(std::string s) {  //valid target
	std::vector<std::string> array;
	std::stringstream ss;
	int counterPlus = 0, counterMinus = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			array.push_back(ss.str());
			counterPlus++;
			this->operation = s[i];
			ss.str(std::string());
		} else if (s[i] == '-') {
			array.push_back(ss.str());
			counterMinus++;
			this->operation = s[i];
			ss.str(std::string());
		} else {
			ss << s[i];
		}
	}
	array.push_back(ss.str());
	if (!((counterPlus == 0 && counterMinus == 1)
			|| (counterPlus == 1 && counterMinus == 0))) {
		return false;
	}
	for (int i = 0; i < array.size(); i++) {
		this->expressionOperands.push_back(array[i]);
	}
	return true;
}

bool OperandFactory::isCharac(std::string &s) {
	int size = s.size();
	if (size > 3 && s[1] == '\'' && s[size - 1] == '\'') {
		char c = toupper(s[0]);
		std::string sub = s.substr(2, size - 3);
		if (c == 'C')
			return true;
		return false;
	}
	return false;
}

bool OperandFactory::isIndexed(std::string &value) {
	std::string s1 = ",x";
	std::string s2 = ",X";
	std::string s3 = ", x";
	std::string s4 = ", X";
	if (value.size() < 2)
		return false;
	if (std::equal(s1.rbegin(), s1.rend(), value.rbegin())
			|| std::equal(s2.rbegin(), s2.rend(), value.rbegin())) {
		value.erase(value.size() - 2, 2);
		return true;
	} else if (std::equal(s3.rbegin(), s3.rend(), value.rbegin())
			|| std::equal(s4.rbegin(), s4.rend(), value.rbegin())) {
		value.erase(value.size() - 3, 3);
		return true;
	}
	return false;
}
std::string OperandFactory::getAbsoluteLiteral(std::string s) {
	std::string temp = s.substr(1, s.length() - 1);
	if (this->isCharac(temp)) {
		return this->getAbsoluteCharacter(temp);
	}
	if (this->isHexachar(temp)) {
		return this->getAbsoluteHexa(temp);
	}

	return temp;
}

std::string OperandFactory::getAbsoluteCharacter(std::string s) {
	std::string copy = s;
	std::string::iterator end_pos = std::remove(copy.begin(), copy.end(), ' ');
	copy.erase(end_pos, copy.end());
	std::string s1 = "C'";
	std::string s2 = "c'";
	if ((std::equal(s1.begin(), s1.end(), copy.begin()))
			|| (std::equal(s2.begin(), s2.end(), copy.begin()))) {
		copy.erase(0, 2);
		copy.erase(copy.size() - 1, 1);
	}
	return copy;
}

std::string OperandFactory::getAbsoluteHexa(std::string s) {
	std::string copy = s;
	std::string::iterator end_pos = std::remove(copy.begin(), copy.end(), ' ');
	copy.erase(end_pos, copy.end());
	std::string s3 = "x'";
	std::string s4 = "X'";
	if ((std::equal(s3.begin(), s3.end(), copy.begin()))
			|| (std::equal(s4.begin(), s4.end(), copy.begin()))) {
		copy.erase(0, 2);
		copy.erase(copy.size() - 1, 1);
	}
	return copy;
}
