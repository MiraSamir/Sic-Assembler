#ifndef SICASSEMBLERV2_MNEMONICFACTORY_H
#define SICASSEMBLERV2_MNEMONICFACTORY_H


#include "../Mnemonic/Mnemonic.h"
#include "../Tables/DirectiveTable.h"
#include "../Tables/OpTable.h"
#include "../Tables/LiteralTable.h"

class MnemonicFactory {
public:
    Mnemonic* create(std::string s);
    MnemonicFactory(OpTable* optable, DirectiveTable* directiveTable, SymbolTable* symbolTable,LiteralTable* literalTable);
    bool isLiteralDef(std::string s);
    void setLTRDEFMODE(bool mode);
    bool getLTRDEFMODE();
private:
    OpTable* opTable;
    DirectiveTable* directiveTable;
    SymbolTable* symbolTable;
    LiteralTable* literalTable;
    Mnemonic* start;
    Mnemonic* end;
    Mnemonic* rsub;
    Mnemonic* instruction;
    Mnemonic* ltorg;
    Mnemonic* word;
    Mnemonic* byte;
    Mnemonic* resw;
    Mnemonic* resb;
    Mnemonic* org;
    Mnemonic* equ;
    Mnemonic* undefined;
    bool LTRDEFMODE;
    Mnemonic* ltrDef;

};


#endif //SICASSEMBLERV2_MNEMONICFACTORY_H
