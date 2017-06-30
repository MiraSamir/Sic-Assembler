#include <cstdlib>
#include <iostream>
#include "PassOne.h"
#include "../Tables/OpTable.h"
#include "../Tables/SymbolTable.h"
#include "../Program.h"
#include "../Validator/Validator.h"
#include "../File handler/FileReader.h"
#include "../File handler/FileWriter.h"
#include "../Utility.h"
#include "../ErrorMessages.h"
#include "../Tables/LiteralTable.h"
#include <vector>
#include <sstream>

PassOne::PassOne(OpTable *op, SymbolTable *sym, DirectiveTable* directiveTable,
		LiteralTable* literalTable) {
	this->locationCounter = new LocationCounter();
	this->opTable = op;
	this->validator = new Validator(op, directiveTable, sym, literalTable);
	this->succeded = true;
	this->symbolTable = sym;
	this->directiveTable = directiveTable;
	this->literalTable = literalTable;
	this->end = false;
	this->flag = false;
}
bool PassOne::generateIntermediateFile(string path, SymbolTable *symbolTable) {
	FileReader* reader = new FileReader(path);
	bool first = true;
	int mnemonicLength;
	AssembleyLine *assemblyLine;
	std::string line;
	FileWriter* writer = new FileWriter(this->evaluateIntermediateFilePath(path));
	writer->writeIntermediateFileHeader();
	while (reader->readLine() && this->locationCounter->isWithinRange()) {
		line = reader->getLine();
		if (line.empty()) continue;
		else if (Utility::isComment(line))
			writer->writeToIntermediateFile(NULL, new CommentLine(line));
		else {
			assemblyLine = this->validator->validate(line);
			handleProgramStart(assemblyLine, first);
			handleProgramEnd(assemblyLine);
			first = false;
			this->checkNullMnemonic(assemblyLine->getMnemonic(), assemblyLine->getError()); // null mnemonic
			this->checkNullOperand(assemblyLine->getOperand(), assemblyLine->getError());  //null operand
			assemblyLine->getLabel()->checkLabelName(assemblyLine->getError(),this->opTable,this->directiveTable); //Invalid Label
			if (checkValidOperand(assemblyLine->getOperand(), assemblyLine->getError())) { //Invalid operand
			} else {  //valid operand
				mnemonicLength = calculateMnemonicLength(assemblyLine->getMnemonic());
				this->locationCounter->setLocationCounter(  //Increase Location Counter
						assemblyLine->getMnemonic()->evaluateLine(
								this->locationCounter->getLocationCounter(),
								mnemonicLength, assemblyLine->getError(),
								assemblyLine->getOperand(),
								assemblyLine->getAddress(),
								assemblyLine->getLabel()));
				if (assemblyLine->getLabel()->getFieldStr().size() != 0) //fill symbol table
					this->fillSymbolTable(assemblyLine->getError(),
							assemblyLine->getLabel()->getFieldStr(),
							assemblyLine->getAddress()->getAddress());
				if (assemblyLine->getOperand()->isLiteral())  //fill literal Table
					this->fillLiteralTable(assemblyLine->getOperand(), assemblyLine->getAddress());
			}
			this->isFirstPassSucceeded(assemblyLine->getError());  //check for errors
			writer->writeToIntermediateFile(assemblyLine, NULL);   //write to intermediate file
			if (assemblyLine->getMnemonic()->isLTORG() || assemblyLine->getMnemonic()->isEnd())
				this->writeLiterals(writer);  //write literal line
		}
	}
	if (!this->locationCounter->isWithinRange()) //check out of range location counter
		writer->writeErrors(ErrorMessages::error.find(12)->second);
	writer->endWriter();
	reader->endReader();
	return this->succeded;
}

string PassOne::evaluateIntermediateFilePath(string path) {
	size_t lastindex = path.find_last_of(".");
	string rawname = path.substr(0, lastindex);
	string extension = path.substr(lastindex, path.size());
	this->IntermediateFilePath = rawname + "$" + extension;
	Program::intermediateFilePath = this->IntermediateFilePath;
	return this->IntermediateFilePath;
}
void PassOne::fillSymbolTable(Error* error, std::string label, int address) {
	int exist = symbolTable->count(Utility::to_upper(label));
	if (label != "") {
		if (exist == 1)
			error->addErrorMessage(ErrorMessages::error.find(11)->second);
		else
			this->symbolTable->insert(
					std::make_pair(Utility::to_upper(label), address));
	}
}

void PassOne::fillLiteralTable(Operand* operand, Address* address) {
	if (operand->getOperandType()->isAsteric()) {
		this->literalTable->insert(
				std::make_pair(address->getAddress(),
						std::make_pair(
								std::make_pair(operand->getFieldStr(), false),
								std::make_pair(3, address->getAddress()))));
	} else {

		this->literalTable->insert(
				std::make_pair(operand->getHexaValue(),
						std::make_pair(
								std::make_pair(operand->getFieldStr(), false),
								std::make_pair(operand->getByteLength(), -1))));
	}
}

void PassOne::handleProgramStart(AssembleyLine* line, bool first) {
	if (line->getMnemonic() != NULL
			&& (!line->getMnemonic()->isSTART() && first)) {
		line->getError()->addErrorMessage(ErrorMessages::error.find(7)->second);
	}
}

void PassOne::handleProgramEnd(AssembleyLine *line) {
	if (line->getMnemonic()->isEnd()) {
		if (end) {
			if (!flag)
				line->getError()->addErrorMessage(
						ErrorMessages::error.find(16)->second);
			flag = true;
		} else
			this->end = true;
	}
}

bool PassOne::checkValidOperand(Operand* operand, Error* error) {
	if (operand->isUndefined() || !operand->isValid()) {
		error->addErrorMessage(ErrorMessages::error.find(8)->second);
		return true;
	}
	return false;
}
void PassOne::checkNullOperand(Operand* operand, Error* error) {
	if (operand->isUndefined())
		error->addErrorMessage(ErrorMessages::error.find(6)->second);
}
void PassOne::checkNullMnemonic(Mnemonic* mnemonic, Error* error) {
	if (mnemonic->isUndefined())
		error->addErrorMessage(ErrorMessages::error.find(5)->second);
}
int PassOne::calculateMnemonicLength(Mnemonic* mnemonic) {
	if (!mnemonic->isUndefined() && mnemonic->isOperation()) {
		std::string copy = Utility::to_upper(mnemonic->getFieldStr());
		return this->opTable->find(copy)->second.second;
	} else
		return 0;
}

void PassOne::writeLiterals(FileWriter* writer) {
	std::vector<string> literalLine;
	std::map<int, std::pair<std::pair<std::string, bool>, std::pair<int, int>>>::iterator it = this->literalTable->begin();
	for (; it != this->literalTable->end(); it++) {
		if (!it->second.first.second) {
			it->second.first.second = true;
			std::stringstream ss;
			ss << hex << std::uppercase << (it->second.second.second);
			literalLine.push_back(ss.str());
			literalLine.push_back("*");
			literalLine.push_back(it->second.first.first);
			writer->writeLiteralLine(literalLine);
			literalLine.clear();
		}
	}
}


void PassOne::isFirstPassSucceeded(Error *error) {
	if (error->getError().size() != 0)
		this->succeded = false;
}
