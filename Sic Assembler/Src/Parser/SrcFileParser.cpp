#include <iostream>
#include "SrcFileParser.h"
#include "../ErrorMessages.h"


SrcFileParser::SrcFileParser(OpTable *optable, DirectiveTable *directiveTable, SymbolTable *symbolTable,LiteralTable* literalTable)
        : Parser(optable, directiveTable, symbolTable,literalTable) {
    this->assembleyLineBuilder = new AssembleyLineBuilder(optable, directiveTable, symbolTable,literalTable);
}



AssembleyLine* SrcFileParser::parse(std::string s) {
    bool ill_format = false;
    if(s.size() > 9) {
        if (s[8] != ' ') {
            ill_format = true;
        }
        std::string label = "";
        label = s.substr(0, 8);
        this->eraseTrailingSpace(label);
        this->assembleyLineBuilder->setLabelField(label);


        std::string mnemonic = "";
        if (s.size() > 14)
            mnemonic = s.substr(9, 6);
        else
            mnemonic = s.substr(9, s.size() - 9 + 1);




        this->eraseTrailingSpace(mnemonic);
        this->assembleyLineBuilder->setMnemonicField(mnemonic);


        std::string operand = "";
        if (s.size() > 34) {
            operand = s.substr(17, 18);
        } else if (s.size() > 17) {
            operand = s.substr(17, s.size() - 17 + 1);
        }
        this->eraseTrailingSpace(operand);
        this->assembleyLineBuilder->setOperandField(operand);

        if (s.size() > 17) {
            if (s[15] != ' ' || s[16] != ' ') {
                ill_format = true;
            }
        }
        std::string comment = "";
        if (s.size() > 35) {
            comment = s.substr(35, s.size() - 35 + 1);
        }
        this->eraseTrailingSpace(comment);
        this->assembleyLineBuilder->setCommentField(comment);

    } else {
        ill_format = true;
    }

    if(ill_format) {
        this->assembleyLineBuilder->setErrorMessage(ErrorMessages::error.find(1)->second);
    }

    this->assembleyLineBuilder->setLTRDEFMODE(false);
    return this->assembleyLineBuilder->build();

}
