
#include "Directive.h"
#include "../Line/Label.h"

Directive::Directive(SymbolTable* symbolTable) :
		Mnemonic(symbolTable) {
}
bool Directive::isEnd() {
	return false;
}

bool Directive::isSTART() {
	return false;
}

bool Directive::isDirective() {
	return true;
}
bool Directive::isLTORG() {
	return false;
}
int Directive::evaluateLine(int currentLC, int length, Error *error,
		Operand *operand, Address *address, Label* label) {
	return 0;
}
bool Directive::requireIntOperand() {
	return false;
}

bool Directive::isRESDirective() {
	return false;
}
