
#include "../Line/UndefinedField.h"

UndefinedField::UndefinedField(SymbolTable *symbolTable) : Mnemonic(symbolTable) {}
UndefinedField::UndefinedField() : Mnemonic (nullptr){}

bool UndefinedField::isUndefined() {
    return true;
}
