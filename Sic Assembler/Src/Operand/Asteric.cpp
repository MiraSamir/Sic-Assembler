#include <sstream>
#include "Asteric.h"
#include "../Utility.h"

bool Asteric::isValid() {
    return true;
}

std::vector<std::string> Asteric::generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error) {
    this->objectCode.clear();
    std::stringstream ss;
    ss << std::hex << lineAddress; // int decimal_value
    std::string s_1(ss.str());
    if(this->isIndexed()) {
        s_1 = this->indexingObcode(s_1);
    }

    this->objectCode.push_back(Utility::to_upper(s_1));
    return this->objectCode;
}
bool Asteric::isAsteric(){
    return true;
}
int Asteric::getOperandAddress(Error* error,int currentLC){
    return currentLC;
}
