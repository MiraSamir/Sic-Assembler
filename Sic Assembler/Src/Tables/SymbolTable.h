#ifndef SICASSEMBLERV2_SYMBOLTABLE_H
#define SICASSEMBLERV2_SYMBOLTABLE_H


#include <string>
#include <map>

class SymbolTable  : public std::map<std::string,int>  {
public:
    SymbolTable();
};

#endif //SICASSEMBLERV2_SYMBOLTABLE_H
