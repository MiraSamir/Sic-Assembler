
#include "../Line/AssembleyLine.h"

#include "../Line/Address.h"
#include "../Line/Comment.h"

void AssembleyLine::setAddress(Address *address) {
	this->address = address;
}

void AssembleyLine::setLabel(Label *label) {
	this->label = label;
}

void AssembleyLine::setMnemonic(Mnemonic *mnemonic) {
	this->mnemonic = mnemonic;
}

void AssembleyLine::setOperand(Operand *operand) {
	this->operand = operand;
}

void AssembleyLine::setComment(Comment *comment) {
	this->comment = comment;
}

void AssembleyLine::setError(Error *error) {
	this->error = error;
}

Objectcode *AssembleyLine::getObjectcode() {
	return objectcode;
}

void AssembleyLine::setObjectcode(Objectcode *objectcode) {
	this->objectcode = objectcode;
}

Mnemonic *AssembleyLine::getMnemonic() {
	return mnemonic;
}

Operand* AssembleyLine::getOperand() {
	return operand;
}

Field *AssembleyLine::getComment() {
	return comment;
}

Error *AssembleyLine::getError() {
	return error;
}

Address* AssembleyLine::getAddress() {
	return this->address;
}

Label* AssembleyLine::getLabel() {
	return this->label;
}

