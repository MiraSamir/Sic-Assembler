#ifndef SICASSEMBLERV2_ASSEMBLEYLINEFACTORY_H
#define SICASSEMBLERV2_ASSEMBLEYLINEFACTORY_H

#include <string>
#include "MnemonicFactory.h"
#include "OperandFactory.h"
#include "Error.h"

#include "../Line/Address.h"
#include "../Line/AssembleyLine.h"
#include "../Line/Comment.h"
#include "../Line/Field.h"
#include "../Line/Objectcode.h"

class AssembleyLineBuilder {
public:
	AssembleyLineBuilder(OpTable *optable, DirectiveTable *directiveTable,
			SymbolTable* symbolTable, LiteralTable* literalTable);
	AssembleyLine* build();
	void setAddressField(std::string s);
	void setLabelField(std::string s);
	void setMnemonicField(std::string s);
	void setOperandField(std::string s);
	void setCommentField(std::string s);
	void setObjectCode(std::string s);
	void setErrorMessage(std::string s);
	void setLTRDEFMODE(bool mode);
	bool getLTRDEFMODE();


private:
	MnemonicFactory* mnemonicFactory;
	OperandFactory* operandFactory;
	AssembleyLine* line;
	Address* address;
	Label* label;
	Mnemonic* mnemonic;
	Operand* operand;
	Comment* comment;
	Error* error;
	Objectcode* objectcode;

	///////////////////////////////////////////////////////////////////////////////////////////
	bool LTRDEFMODE;
	////////////////////////////////////////////////////////////////////////////////////////////

};

#endif //SICASSEMBLERV2_ASSEMBLEYLINEFACTORY_H
