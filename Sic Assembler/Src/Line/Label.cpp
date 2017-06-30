#include "../Line/Label.h"

#include <iostream>
#include "../Utility.h"
#include <algorithm>

void Label::checkLabelName(Error* error, OpTable* optable,
		DirectiveTable* directiveTable) {
	std::string copy = Utility::to_upper(this->getFieldStr());
	int exist = optable->count(copy);
	bool found = std::find(directiveTable->begin(), directiveTable->end(), copy)
			!= directiveTable->end();
	if (exist != 0 || found)
		error->addErrorMessage(ErrorMessages::error.find(17)->second);

}
