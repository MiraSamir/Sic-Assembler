#include "../Line/Error.h"

#include <string>

void Error::addErrorMessage(std::string error){
    this->error.push_back(error);
}

std::vector<std::string> &Error::getError() {
    return error;
}

void Error::setError(std::vector<std::string> error) {
    this->error = error;
}
