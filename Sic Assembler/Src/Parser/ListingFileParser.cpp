#include "ListingFileParser.h"

ListingFileParser::ListingFileParser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable *symbolTable,LiteralTable* literalTable)
        : GeneratedFileParser(optable, directiveTable, symbolTable,literalTable) {}

void ListingFileParser::parseListingFile(std::string line) {
    std::string comment = "";
    if (line.size() > 120) {
        comment = line.substr(120, line.size() - 120 + 1);
    }
    this->assembleyLineBuilder->setCommentField(comment);
    std::string obCode = "";
    if (line.size() > 100)
        obCode = line.substr(100, 20);
    this->eraseLeadingSpace(obCode);
    this->eraseTrailingSpace(obCode);
    this->assembleyLineBuilder->setObjectCode(obCode);
}
