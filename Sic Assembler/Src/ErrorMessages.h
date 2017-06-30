
#ifndef SICASSEMBLERV2_ERRORMESSAGES_H
#define SICASSEMBLERV2_ERRORMESSAGES_H

#include <string>
#include <map>

class ErrorMessages{
public:
    ErrorMessages();
    static std::map<int, std::string> error;

};
#endif //SICASSEMBLERV2_ERRORMESSAGES_H
