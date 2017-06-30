#ifndef SICASSEMBLERV2_VALIDATOR_H
#define SICASSEMBLERV2_VALIDATOR_H

#include "../Parser/Parser.h"
#include <string>

class Validator {
public:
    Validator(OpTable *optable, DirectiveTable *directiveTable, SymbolTable* symbolTable,LiteralTable* literalTable);
    AssembleyLine* validate(std::string s);

private:
    Parser* parser;
    AssembleyLine* assemblyLine;
    void checkFormat(AssembleyLine* line);
    void checkLabel(AssembleyLine* line, Field* label);
    void checkMnemonic(AssembleyLine* line, Mnemonic* mnemonic);
    void checkOperand(AssembleyLine* line, Operand* operand);
    void eraseTrailingSpace(std::string &s);
    void eraseLeadingSpace(std::string &s);
    bool isHex(std::string &s);


};
#endif //SICASSEMBLERV2_VALIDATOR_Hs
