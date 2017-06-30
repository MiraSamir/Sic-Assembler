
#include "../Line/Objectcode.h"

#include <algorithm>
#include <sstream>
#include <iostream>
#include "../Operand/Operand.h"
#include "../Tables/OpTable.h"
#include "../Tables/SymbolTable.h"
#include "../Mnemonic/Mnemonic.h"
#include "../Utility.h"
#include "../ErrorMessages.h"


void Objectcode::generateObjectCode(OpTable *opTable, SymbolTable *symbolTable,
		Mnemonic *mnemonic, Operand *operand, Error* error, int address) {
	this->obcodestrvec.clear();
	std::vector<std::string> opcode = operand->generateObjectcode(symbolTable,
			address, error);
	std::string mncode = "";
	if (!(mnemonic->isEnd() || mnemonic->isSTART() || error->getError().size() > 0 || mnemonic->isORG() || mnemonic->isEQU() || mnemonic->isRESDirective())) {
		if (mnemonic->isLTRDEF()) {
			std::string mncode = mnemonic->generateObjectcode(symbolTable,
					address, error);
			opcode.clear();
			opcode.push_back("");
			this->obcodestrvec = this->concObjectcode(mncode, opcode);
		} else {
			std::string mncode = mnemonic->generateObjectcode(opTable);
			this->obcodestrvec = this->concObjectcode(mncode, opcode);

		}

	}
}

std::vector<std::string> Objectcode::concObjectcode(std::string mncode, std::vector<std::string> opcode) {
    std::vector<std::string>::iterator it;
    std::vector<std::string> obcode;

    for (it = opcode.begin(); it < opcode.end(); it++) {

        this->SICfillOperandCode(*it, mncode);
        obcode.push_back(mncode + *it);
    }
    return obcode;
}


void Objectcode::SICfillOperandCode(std::string &opcode, std::string mnemonic) {
    std::string fill = "";
    int fillnumber = 6;
    if(opcode.size() <= 4) {
        if(mnemonic.size() <= 2 && mnemonic.size() != 0) {
            fillnumber = 4;
        } else if(mnemonic.size() > 2) {
            fillnumber = 0;
        }
        for(unsigned int i = 0; i < (fillnumber -  opcode.size()); i++) {
            fill = fill + "0";
        }
        opcode = fill + opcode;
    }

}


void Objectcode::setObjCodestr(std::string s) {
    this->obcodestr = s;
}


std::string Objectcode::getObjCodeStr() {
    return this->obcodestr;
}

std::vector<std::string> Objectcode::getObjCodeStrvec() {
    return this->obcodestrvec;
}


void Objectcode::addtoObjCodeStrVec(std::string s) {
    this->obcodestrvec.push_back(s);
}

