

#include "OpTable.h"


OpTable::OpTable() {
    this->insert(std::make_pair("ADD", std::pair<int,int> (0x18,3)));
    this->insert(std::make_pair("AND", std::pair<int,int> (0x40,3)));
    this->insert(std::make_pair("COMP", std::pair<int,int> (0x28,3)));
    this->insert(std::make_pair("DIV", std::pair<int,int> (0x24,3)));
    this->insert(std::make_pair("J", std::pair<int,int> (0x3C,3)));
    this->insert(std::make_pair("JEQ", std::pair<int,int> (0x30,3)));
    this->insert(std::make_pair("JGT", std::pair<int,int> (0x34,3)));
    this->insert(std::make_pair("JLT", std::pair<int,int> (0x38,3)));
    this->insert(std::make_pair("JSUB", std::pair<int,int> (0x48,3)));
    this->insert(std::make_pair("LDA", std::pair<int,int> (0x00,3)));
    this->insert(std::make_pair("LDCH", std::pair<int,int> (0x50,3)));
    this->insert(std::make_pair("LDL", std::pair<int,int> (0x08,3)));
    this->insert(std::make_pair("LDX", std::pair<int,int> (0x04,3)));
    this->insert(std::make_pair("MUL", std::pair<int,int> (0x20,3)));
    this->insert(std::make_pair("OR", std::pair<int,int> (0x44,3)));
    this->insert(std::make_pair("RD", std::pair<int,int> (0xD8,3)));
    this->insert(std::make_pair("RSUB", std::pair<int,int> (0x4C,3)));
    this->insert(std::make_pair("STA", std::pair<int,int> (0x0C,3)));
    this->insert(std::make_pair("STCH", std::pair<int,int> (0x54,3)));
    this->insert(std::make_pair("STL", std::pair<int,int> (0x14,3)));
    this->insert(std::make_pair("STX", std::pair<int,int> (0x10,3)));
    this->insert(std::make_pair("SUB", std::pair<int,int> (0x1C,3)));
    this->insert(std::make_pair("TD", std::pair<int,int> (0xE0,3)));
    this->insert(std::make_pair("TIX", std::pair<int,int> (0x2C,3)));
    this->insert(std::make_pair("WD", std::pair<int,int> (0xDC,3)));

}
