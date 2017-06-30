#ifndef SICASSEMBLERV2_MNEMONIC_H
#define SICASSEMBLERV2_MNEMONIC_H


#include "../Line/Error.h"
#include "../Line/Address.h"
#include "../Line/Field.h"
#include "../Line/Label.h"
#include "../Operand/Operand.h"
#include "../Tables/SymbolTable.h"
#include "../Tables/OpTable.h"
#include "../Tables/LiteralTable.h"

class Mnemonic : public Field {
public:
    Mnemonic(SymbolTable* symbolTable);
    virtual bool isSTART();
    virtual bool isEnd();
    virtual bool isLTORG();
    virtual std::string getFieldStr();
    virtual void setFieldStr(std::string s);
    virtual int evaluateLine(int currentLC, int length, Error *error, Operand *operand,Address *address,Label *label);
    virtual int evaluateStartingAddress(Operand* operand);
    virtual int evaluateProgramSize(int currentLC);
    virtual bool isDirective();
    virtual bool isOperation();
    virtual bool requireIntOperand();
    virtual bool isWORD();
    virtual bool isBYTE();
    virtual bool isRESDirective();
    std::string generateObjectcode(OpTable* opTable);
    virtual bool isUndefined();
    virtual bool isLTRDEF();
    /////////////////////////////////////////////////////////////////////////////////
    virtual void setLiteralTable(LiteralTable* literalTable);
    virtual std::string generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error);
    /////////////////////////////////////////////////////////////////////////////////
    virtual bool isORG();
    virtual bool isEQU();
    ///////////////////////////////////////////////////////////////////////////////////////

protected:
    SymbolTable* symbolTable;


};
#endif //SICASSEMBLERV2_MNEMONIC_H
