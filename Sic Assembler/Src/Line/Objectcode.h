
#ifndef SICASSEMBLERV2_OBJECTCODE_H
#define SICASSEMBLERV2_OBJECTCODE_H

#include "../Tables/DirectiveTable.h"
#include "../Tables/SymbolTable.h"
#include "../Tables/OpTable.h"
#include "../Mnemonic/Mnemonic.h"
#include "../Operand/Operand.h"

class Objectcode {
public:
    void generateObjectCode(OpTable* opTable, SymbolTable* symbolTable, Mnemonic* mnemonic, Operand* operand, Error* error, int address);
    std::string getObjCodeStr();
    std::vector<std::string> getObjCodeStrvec();
    void addtoObjCodeStrVec(std::string s);
    void setObjCodestr(std::string s);
private:
    std::string obcodestr;
    std::vector<std::string> obcodestrvec;
    std::vector<std::string> concObjectcode(std::string mncode, std::vector<std::string > opcode);
    void SICfillOperandCode(std::string &opcode, std::string mnemonic);

};
#endif //SICASSEMBLERV2_OBJECTCODE_H
