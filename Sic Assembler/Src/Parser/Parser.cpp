#include <algorithm>
#include <iostream>
#include "Parser.h"

Parser::Parser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable *symbolTable,LiteralTable* literalTable) {
    this->symbolTable = symbolTable;
    this->directiveTable = directiveTable;
    this->optable = optable;
    this->literalTable = literalTable;
}


void Parser::eraseTrailingSpace(std::string &s) {
    s.erase(
            std::find_if(s.rbegin(), s.rend(),
                         std::bind1st(std::not_equal_to<char>(), ' ')).base(),
            s.end());
}

void Parser::eraseLeadingSpace(std::string &s) {
    s.erase(s.begin(),
            std::find_if(s.begin(), s.end(),
                         std::bind1st(std::not_equal_to<char>(), ' ')));
}

AssembleyLine* Parser::parse(std::string s) {
    return nullptr;
}

