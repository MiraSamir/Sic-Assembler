

#include <sstream>
#include "Character.h"
#include "../Utility.h"
#include "../ErrorMessages.h"
#include <algorithm>

bool Character::isValid() {
    return (this->getAbsoluteOperand().size() <= LIMITSIZE);
}



bool Character::isDirectiveOperand() {
    return true;
}

bool Character::isCharOperand() {
    return true;
}

int Character::getByteLength(){
    return (this->getAbsoluteOperand().size());
}
std::vector<std::string> Character::generateObjectcode(SymbolTable *symbolTable, int lineAddress, Error* error) {
    this->objectCode.clear();
    std::stringstream ss;
    for(unsigned int i=0; i< this->getAbsoluteOperand().size(); ++i)
        ss << std::hex << (int)this->getAbsoluteOperand()[i];
    std::string mystr = ss.str();
    if(this->isIndexed()) {
        mystr = this->indexingObcode(mystr);
    }
    this->objectCode.push_back(Utility::to_upper(mystr));
    return this->objectCode;
}
int Character::getOperandAddress(Error* error, int currentLC) {
    error->addErrorMessage(ErrorMessages::error.find(6)->second);
    return currentLC;
}
