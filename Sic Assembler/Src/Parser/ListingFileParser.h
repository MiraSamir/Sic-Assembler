


#ifndef SICASSEMBLERV2_LISTINGFILEPARSER_H
#define SICASSEMBLERV2_LISTINGFILEPARSER_H


#include "GeneratedFileParser.h"
#include "../Tables/LiteralTable.h"

class ListingFileParser : public GeneratedFileParser{
public:
    ListingFileParser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable *symbolTable,LiteralTable* literalTable);
    void parseListingFile(std::string s);

};


#endif //SICASSEMBLERV2_LISTINGFILEPARSER_H
