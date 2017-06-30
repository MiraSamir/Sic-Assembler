#include "ErrorMessages.h"


std::map<int, std::string> ErrorMessages::error = {
        {1, "***ERROR: ASSEMBLY LINE ILL-FORMATED."},
        {2, "***ERROR: LABEL FIELD MUST BEGIN WITH A LETTER"},
        {3, "***ERROR: MNEMONIC: INVALID FORMAT."},
        {4, "***ERROR: OPCODE FIELD IS REQUIRED."},
        {5, "***ERROR: MNEMONIC DOESN'T EXIST."},
        {6, "***ERROR: INVALID OPERAND FIELD."},
        {7, "***ERROR: PRPGRAM MUST START WITH A UNIQUE START STATEMENT."},
        {8, "***ERROR: OPERAND FIELD VALUE OUT OF RANGE"},
        {9, "***ERROR: OPERAND FIELD IS REQUIRED"},
        {10,"***ERROR: OPERAND FIELD MUST BE EMPTY"},
        {11,"***ERROR: DUPLICATE LABEL."},
        {12,"***ERROR: MEMORY IS OUT OF RANGE."},
        {13,"***ERROR: UNDEFINED LABEL."},
        {14,"***ERROR: LABEL MUST BE BLANK"},
        {15,"***ERROR: LABEL REQUIRED"},
        {16,"***ERROR: END MNEMONIC MUST BE THE FINAL LINE."},
        {17,"***ERROR: LABEL FIELD CANNOT BE A MNEMONIC."}
};
