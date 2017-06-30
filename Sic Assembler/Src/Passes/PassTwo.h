#ifndef SICASSEMBLERV2_PASSTWO_H
#define SICASSEMBLERV2_PASSTWO_H


#include "../Line/AssembleyLine.h"
#include "../Tables/OpTable.h"
#include "../Tables/SymbolTable.h"
#include "../Validator/Validator.h"
#include "../Parser/Parser.h"


using namespace std;

class PassTwo {
public:
    PassTwo(OpTable *op, SymbolTable *sym, DirectiveTable* directiveTable, LiteralTable* literalTable1);
    bool generateListingFile();
    void generateObjectCodeFile();


private:
    OpTable *opTable;
    SymbolTable *symbolTable;
    DirectiveTable* directiveTable;
    std::string listingFilePath;
    const int recordLength = 69;
    Parser *parser;
    bool succeed;
    LiteralTable* literalTable;
    std::string evaluateListingFilePath(std::string path);
    std::string evaluateRecordFilePath(std::string path);
};




#endif //SICASSEMBLERV2_PASSTWO_H
