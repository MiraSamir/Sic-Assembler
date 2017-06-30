
#ifndef SICASSEMBLERV2_CONTROLLER_H
#define SICASSEMBLERV2_CONTROLLER_H


#include "../Tables/OpTable.h"

class Controller {
public:
    Controller();
    void assemble(std::string srcPath);
private:
    OpTable *opTable;

};
#endif //SICASSEMBLERV2_CONTROLLER_H

