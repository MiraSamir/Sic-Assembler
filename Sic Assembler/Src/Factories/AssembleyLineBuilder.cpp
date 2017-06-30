#include <iostream>
#include <cstdlib>
#include "AssembleyLineBuilder.h"
#include "../Validator/Validator.h"
#include <iostream>
#include <cstdlib>
#include "AssembleyLineBuilder.h"

#include "../Line/AssembleyLine.h"
#include "../Line/AssembleyLine.h"
#include "../Line/Comment.h"
#include "../Line/Comment.h"
#include "../Line/Label.h"
#include "../Line/Label.h"
#include "../Validator/Validator.h"

AssembleyLineBuilder::AssembleyLineBuilder(OpTable *optable,
		DirectiveTable *directiveTable, SymbolTable* symbolTable,
		LiteralTable* literalTable) {
	this->operandFactory = new OperandFactory(literalTable, symbolTable);
	this->mnemonicFactory = new MnemonicFactory(optable, directiveTable,
			symbolTable, literalTable);
	this->error = new Error();
	this->address = new Address();
	this->label = new Label();
	this->comment = new Comment();
	this->line = new AssembleyLine();
	this->objectcode = new Objectcode();
}

void AssembleyLineBuilder::setAddressField(std::string s) {
	int int_s = static_cast<int>(std::strtoul(s.c_str(), NULL, 16));
	address->setAddress(int_s);
}

void AssembleyLineBuilder::setLabelField(std::string s) {
	this->label->setFieldStr(s);
}

void AssembleyLineBuilder::setMnemonicField(std::string s) {

	this->mnemonic = this->mnemonicFactory->create(s);
}

void AssembleyLineBuilder::setOperandField(std::string s) {
	if (this->mnemonic != NULL)
		this->operandFactory->setDirectiveMood(
				this->mnemonic->requireIntOperand());
	else
		this->operandFactory->setDirectiveMood(false);
	this->operand = this->operandFactory->create(s);
}

void AssembleyLineBuilder::setErrorMessage(std::string s) {
	this->error->addErrorMessage(s);
}

void AssembleyLineBuilder::setCommentField(std::string s) {
	this->comment->setFieldStr(s);
}

AssembleyLine* AssembleyLineBuilder::build() {

	line->setAddress(this->address);
	line->setLabel(this->label);
	line->setOperand(this->operand);
	line->setMnemonic(this->mnemonic);
	line->setComment(this->comment);
	line->setError(this->error);
	line->setObjectcode(this->objectcode);
	//   this->error->getError().clear();

	return line;
}

void AssembleyLineBuilder::setObjectCode(std::string s) {
	this->objectcode->setObjCodestr(s);
}


void AssembleyLineBuilder::setLTRDEFMODE(bool mode) {
	this->LTRDEFMODE = mode;
	this->mnemonicFactory->setLTRDEFMODE(mode);
}

bool AssembleyLineBuilder::getLTRDEFMODE() {
	return this->LTRDEFMODE;
}

