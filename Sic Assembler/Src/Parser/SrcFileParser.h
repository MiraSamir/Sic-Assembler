
#ifndef SICASSEMBLERV2_SRCFILEPARSER_H
#define SICASSEMBLERV2_SRCFILEPARSER_H

#include "Parser.h"

class SrcFileParser : public Parser {
public:
    SrcFileParser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable *symbolTable,LiteralTable* literalTable);
    AssembleyLine* parse(std::string s);
};

#endif //SICASSEMBLERV2_SRCFILEPARSER_H
