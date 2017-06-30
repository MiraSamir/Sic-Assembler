#include "GeneratedFileParser.h"

GeneratedFileParser::GeneratedFileParser(OpTable *optable,
		DirectiveTable *directiveTable, SymbolTable* symbolTable,
		LiteralTable* literalTable) :
		Parser(optable, directiveTable, symbolTable, literalTable) {
	this->assembleyLineBuilder = new AssembleyLineBuilder(optable,
			directiveTable, symbolTable, literalTable);
}

AssembleyLine* GeneratedFileParser::parse(std::string line) {

	if (line.size() > 0) {
		std::string address = line.substr(20, 4);
		this->eraseLeadingSpace(address);
		this->eraseTrailingSpace(address);
		this->assembleyLineBuilder->setAddressField(address);
		std::string label = "";
		if (line.size() > 40)
			label = line.substr(40, 8);
		this->eraseLeadingSpace(label);
		this->eraseTrailingSpace(label);
		this->assembleyLineBuilder->setLabelField(label);
		std::string mnemonic = "";
		if (line.size() > 60)
			mnemonic = line.substr(60, 19);
		this->eraseLeadingSpace(mnemonic);
		this->eraseTrailingSpace(mnemonic);
		this->assembleyLineBuilder->setMnemonicField(mnemonic);
		std::string operand = "";
		if (line.size() > 98)
			operand = line.substr(80, 18);
		else
			operand = line.substr(80, line.size() - 80 + 1);
		this->eraseLeadingSpace(operand);
		this->eraseTrailingSpace(operand);
		this->assembleyLineBuilder->setOperandField(operand);

		this->parseIntermediateFile(line);
		this->parseListingFile(line);
	}
	this->assembleyLineBuilder->setLTRDEFMODE(true);
	return this->assembleyLineBuilder->build();
}

void GeneratedFileParser::parseIntermediateFile(std::string s) {

}

void GeneratedFileParser::parseListingFile(std::string s) {

}
