
#include "DirectiveTable.h"


DirectiveTable::DirectiveTable() {
    this->push_back("START");
    this->push_back("END");
    this->push_back("ORG");
    this->push_back("EGU");
    this->push_back("RESW");
    this->push_back("RESB");
    this->push_back("WORD");
    this->push_back("BYTE");
    this->push_back("LTORG");
    this->push_back("EQU");
}
