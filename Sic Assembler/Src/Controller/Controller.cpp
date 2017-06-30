#include "Controller.h"
#include "../Tables/SymbolTable.h"
#include "../Passes/PassOne.h"
#include "../Passes/PassTwo.h"
#include "../Tables/LiteralTable.h"
#include <iostream>
Controller::Controller() {
	this->opTable = new OpTable();
}

void Controller::assemble(string srcPath) {

	SymbolTable *symbolTable = new SymbolTable();
	DirectiveTable *directiveTable = new DirectiveTable();
	LiteralTable* literalTable = new LiteralTable();

	PassOne *ps1 = new PassOne(this->opTable, symbolTable, directiveTable,
			literalTable);
	if (ps1->generateIntermediateFile(srcPath, symbolTable)) {

		PassTwo *ps2 = new PassTwo(opTable, symbolTable, directiveTable,
				literalTable);
		if (ps2->generateListingFile()) {
			ps2->generateObjectCodeFile();
		}

	}
}
