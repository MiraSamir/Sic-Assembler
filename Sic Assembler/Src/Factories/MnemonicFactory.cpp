#include "MnemonicFactory.h"
#include "../Utility.h"
#include "../Mnemonic/Instruction.h"
#include "../Mnemonic/Start.h"
#include "../Mnemonic/End.h"
#include "../Mnemonic/Org.h"
#include "../Mnemonic/Equ.h"
#include "../Mnemonic/Resw.h"
#include "../Mnemonic/Resb.h"
#include "../Mnemonic/Word.h"
#include "../Mnemonic/Byte.h"
#include "../Mnemonic/RSUB.h"
#include "../Mnemonic/LTORG.h"
#include "../Line/UndefinedField.h"
#include "../Line/LiteralDefinition.h"
#include <algorithm>
#include <iostream>

MnemonicFactory::MnemonicFactory(OpTable *optable,
                                 DirectiveTable *directiveTable, SymbolTable* symbolTable,
                                 LiteralTable* literalTable) {
    this->opTable = optable;
    this->directiveTable = directiveTable;
    this->symbolTable = symbolTable;
    this->literalTable = literalTable;
    this->LTRDEFMODE = false;
    this->start = new Start(this->symbolTable);
    this->end = new End(this->symbolTable, this->literalTable);
    this->resw = new Resw(this->symbolTable);
    this->rsub = new RSUB(this->symbolTable);
    this->instruction = new Instruction(this->symbolTable);
    this->word = new Word(this->symbolTable);
    this->resb = new Resb(this->symbolTable);
    this->byte = new Byte(this->symbolTable);
    this->ltorg = new LTORG(this->symbolTable, this->literalTable);
    this->undefined = new UndefinedField(this->symbolTable);
    this->org = new Org(this->symbolTable, this->literalTable);
    this->ltrDef = new LiteralDefinition(this->symbolTable);
    this->equ =  new Equ(this->symbolTable, this->literalTable);
}

Mnemonic* MnemonicFactory::create(std::string s) {
    std::string copy = Utility::to_upper(s);
    std::unordered_map<std::string, std::pair<int, int>>::iterator it =
            opTable->find(copy);
    if (it != opTable->end()) {
        if (copy.compare("RSUB") == 0) {
            this->rsub->setFieldStr(s);
            return this->rsub;
        } else {
            this->instruction->setFieldStr(s);
            return this->instruction;
        }
    }else if (std::find(this->directiveTable->begin(), this->directiveTable->end(),
                  copy) != this->directiveTable->end()) {
        if (copy.compare("START") == 0) {
            this->start->setFieldStr(s);
            return this->start;
        } else if (copy.compare("END") == 0) {
            this->end->setFieldStr(s);
            return this->end;
        } else if (copy.compare("ORG") == 0) {
            this->org->setFieldStr(s);
            return this->org;
        } else if (copy.compare("EQU") == 0) {
            this->equ->setFieldStr(s);
            return this->equ;
        } else if (copy.compare("RESW") == 0) {
            this->resw->setFieldStr(s);
            return this->resw;
        } else if (copy.compare("RESB") == 0) {
            this->resb->setFieldStr(s);
            return this->resb;
        } else if (copy.compare("WORD") == 0) {
            this->word->setFieldStr(s);
            return this->word;
        } else if (copy.compare("BYTE") == 0) {
            this->byte->setFieldStr(s);
            return this->byte;
        } else if (copy.compare("LTORG") == 0) {
            this->ltorg->setFieldStr(s);
            return this->ltorg;
        }

    } else if (this->isLiteralDef(s)) {
        this->ltrDef->setFieldStr(s);
        this->ltrDef->setLiteralTable(this->literalTable);
        return this->ltrDef;
    } else {
        this->undefined->setFieldStr(s);
        return this->undefined;
    }
    return NULL;
}

void MnemonicFactory::setLTRDEFMODE(bool mode) {
    this->LTRDEFMODE = mode;
}

bool MnemonicFactory::getLTRDEFMODE() {
    return this->LTRDEFMODE;
}

bool MnemonicFactory::isLiteralDef(std::string s) {
    if(s[0] == '=')
        return true;
    return false;
}
