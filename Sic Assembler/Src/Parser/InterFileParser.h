//
// Created by me on 5/22/2017.
//

#ifndef SICASSEMBLERV2_INTERFILEPARSER_H
#define SICASSEMBLERV2_INTERFILEPARSER_H


#include "GeneratedFileParser.h"

class InterFileParser : public GeneratedFileParser{
public:
    InterFileParser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable *symbolTable,LiteralTable* literalTable);
    void parseIntermediateFile(std::string s);


};


#endif //SICASSEMBLERV2_INTERFILEPARSER_H
