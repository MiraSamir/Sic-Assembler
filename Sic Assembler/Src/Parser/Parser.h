#ifndef SICASSEMBLERV2_PARSER_H
#define SICASSEMBLERV2_PARSER_H


#include <string>

#include "../Line/AssembleyLine.h"
#include "../Factories/AssembleyLineBuilder.h"

class Parser {
public:
    Parser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable* symbolTable,LiteralTable* literalTable);
    virtual AssembleyLine* parse(std::string s);

protected:
    AssembleyLineBuilder* assembleyLineBuilder;
    void eraseTrailingSpace(std::string &s);
    void eraseLeadingSpace(std::string &s);
    OpTable* optable;
    DirectiveTable* directiveTable;
    SymbolTable* symbolTable;
    LiteralTable* literalTable;

};


#endif //SICASSEMBLERV2_PARSER_H
