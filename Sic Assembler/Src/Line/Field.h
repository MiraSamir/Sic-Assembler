//
// Created by me on 5/19/2017.
//

#ifndef SICASSEMBLERV2_FIELD_H
#define SICASSEMBLERV2_FIELD_H

#include <string>

class Field {

public:
	virtual std::string getFieldStr();
	virtual void setFieldStr(std::string s);
private:
	std::string field;
};
#endif //SICASSEMBLERV2_FIELD_H
