#include <algorithm>
#include <iostream>
#include "Validator.h"
#include "../Parser/Parser.h"
#include "../Parser/SrcFileParser.h"
#include "../ErrorMessages.h"
#include "../Utility.h"

Validator::Validator(OpTable *optable, DirectiveTable *directiveTable, SymbolTable* symbolTable,LiteralTable* literalTable) {

    this->assemblyLine = new AssembleyLine();
    this->parser = new SrcFileParser(optable, directiveTable, symbolTable,literalTable);
}

AssembleyLine* Validator::validate(std::string s) {
    this->assemblyLine = parser->parse(s);

    checkFormat(this->assemblyLine);
    return this->assemblyLine;
}

void Validator::checkFormat(AssembleyLine* line) {
    checkLabel(line, line->getLabel());
    if(line->getMnemonic() != NULL)
        checkMnemonic(line, line->getMnemonic());
    if(line->getOperand() != NULL)
        checkOperand(line, line->getOperand());
}


void Validator::checkLabel(AssembleyLine* line, Field* label) {
    std::string s = label->getFieldStr();
    if(!Utility::isWhiteSpacesOnly(s)) {   //Label can be empty
        char ch = s[0];
        if(!((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A'))){
            this->assemblyLine->getError()->addErrorMessage(ErrorMessages::error.find(2)->second);
        }
        this->eraseTrailingSpace(s);
        this->assemblyLine->getLabel()->setFieldStr(s);
    }
}

void Validator::checkMnemonic(AssembleyLine* line, Mnemonic* mnemonic) {
    std::string s = mnemonic->getFieldStr();
    if(!Utility::isWhiteSpacesOnly(s)) {
        if(!Utility::isLettersOnly(s)) {
            this->assemblyLine->getError()->addErrorMessage(ErrorMessages::error.find(3)->second);
        }

    } else {
        this->assemblyLine->getError()->addErrorMessage(ErrorMessages::error.find(4)->second);
    }
    this->eraseTrailingSpace(s);
    this->assemblyLine->getMnemonic()->setFieldStr(s);

}


void Validator::eraseTrailingSpace(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),std::bind1st(std::not_equal_to<char>(), ' ')).base(),s.end());
}


void Validator::checkOperand(AssembleyLine* line, Operand* operand) {
    std::string s = operand->getFieldStr();
    if(!Utility::isWhiteSpacesOnly(s)) {
        this->eraseTrailingSpace(s);
        this->assemblyLine->getOperand()->setFieldStr(s);
    }

}
