//
// Created by me on 5/22/2017.
//

#include "InterFileParser.h"

InterFileParser::InterFileParser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable *symbolTable,LiteralTable* literalTable)
        : GeneratedFileParser(optable, directiveTable, symbolTable,literalTable) {}


/*
AssembleyLine* InterFileParser::parse(std::string line) {
    return GeneratedFileParser::parse(line);
}
*/





void InterFileParser::parseIntermediateFile(std::string line) {
    std::string comment = "";
    if (line.size() > 100) {
        comment = line.substr(100, line.size() - 100 + 1);
    }
    assembleyLineBuilder->setCommentField(comment);
}
