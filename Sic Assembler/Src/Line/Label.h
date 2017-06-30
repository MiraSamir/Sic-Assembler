#ifndef SICASSEMBLERV2_LABEL_H
#define SICASSEMBLERV2_LABEL_H


#include <string>

#include "../Line/Error.h"
#include "../Line/Field.h"
#include "../ErrorMessages.h"
#include "../Tables/OpTable.h"
#include "../Tables/DirectiveTable.h"

class Label : public Field {
public:
   void checkLabelName(Error* error,OpTable* optable,DirectiveTable* directiveTable);
};


#endif //SICASSEMBLERV2_LABEL_H
