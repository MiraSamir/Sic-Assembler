#ifndef SICASSEMBLERV2_ASSEMBLEYLINE_H
#define SICASSEMBLERV2_ASSEMBLEYLINE_H

#include "../Line/Address.h"
#include "../Line/Comment.h"
#include "../Line/Error.h"
#include "../Line/Field.h"
#include "../Line/Label.h"
#include "../Line/Objectcode.h"
#include "../Tables/DirectiveTable.h"
#include "../Tables/OpTable.h"
#include "../Mnemonic/Mnemonic.h"
#include "../Operand/Operand.h"

class AssembleyLine {
public:
	void setAddress(Address *address);
	void setLabel(Label *label);
	void setMnemonic(Mnemonic *mnemonic);
	void setOperand(Operand *operand);
	void setComment(Comment *comment);
	void setError(Error *error);
	Objectcode *getObjectcode();
	void setObjectcode(Objectcode *objectcode);
	Mnemonic *getMnemonic();
	Operand *getOperand();
	Field *getComment();
	Error *getError();
	Label* getLabel();
	Address* getAddress();

private:
	Mnemonic* mnemonic;
	Operand* operand;
	Comment* comment;
	Error* error;
	Objectcode* objectcode;
	Address* address;
	Label* label;

};
#endif //SICASSEMBLERV2_ASSEMBLEYLINE_H
