#ifndef SICASSEMBLERV2_GENERATEDFILEPARSER_H
#define SICASSEMBLERV2_GENERATEDFILEPARSER_H

#include "Parser.h"
#include "../Tables/LiteralTable.h"

class GeneratedFileParser : public Parser {
public:
    GeneratedFileParser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable* symbolTable,LiteralTable* literalTable);
    AssembleyLine* parse(std::string line);
    virtual void parseIntermediateFile(std::string s);
    virtual void parseListingFile(std::string s);
};
#endif //SICASSEMBLERV2_GENERATEDFILEPARSER_H
