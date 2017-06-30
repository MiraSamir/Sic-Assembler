
#ifndef SICASSEMBLERV2_PASSONE_H
#define SICASSEMBLERV2_PASSONE_H

#include "../Tables/OpTable.h"
#include "../Tables/SymbolTable.h"
#include "../Tables/LiteralTable.h"
#include "../LocationCounter.h"
#include "../Validator/Validator.h"
#include "../File handler/FileWriter.h"
#include "../Tables/DirectiveTable.h"
using namespace std;
class PassOne {
public:
	PassOne(OpTable *op, SymbolTable *sym, DirectiveTable* directiveTable,
			LiteralTable* literalTable);
	bool generateIntermediateFile(std::string path, SymbolTable *symbolTable);
private:
	OpTable *opTable;
	Validator *validator;
	SymbolTable *symbolTable;
	LiteralTable* literalTable;
	DirectiveTable* directiveTable;
	LocationCounter* locationCounter;
	bool succeded, end, flag;
	std::string IntermediateFilePath;
	void isFirstPassSucceeded(Error* error);
	std::string evaluateIntermediateFilePath(std::string path);
	void fillSymbolTable(Error* error, std::string label, int address);
	void fillLiteralTable(Operand* operand, Address* address);
	void handleProgramStart(AssembleyLine* line, bool first);
	void handleProgramEnd(AssembleyLine* line);
	void checkNullOperand(Operand* operand, Error* error);
	void checkNullMnemonic(Mnemonic* mnemonic, Error* error);
	void writeLiterals(FileWriter* writer);
	bool checkValidOperand(Operand* operand, Error* error);
	int calculateMnemonicLength(Mnemonic* mnemonic);

};

#endif //SICASSEMBLERV2_PASSONE_H
