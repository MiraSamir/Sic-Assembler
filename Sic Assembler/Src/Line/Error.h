
#ifndef SICASSEMBLERV2_ERRROR_H
#define SICASSEMBLERV2_ERRROR_H

#include <string>
#include <vector>

class Error{

public:
    void addErrorMessage(std::string error);
    std::vector<std::string> &getError();
    void setError(std::vector<std::string> error);

private:
    std::vector<std::string> error;


};
#endif //SICASSEMBLERV2_ERRROR_H
