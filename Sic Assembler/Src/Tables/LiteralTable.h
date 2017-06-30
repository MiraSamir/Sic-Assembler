#ifndef LITERALTABLE_H_
#define LITERALTABLE_H_

#include <map>

// key --->hex, values are name ,bool, length, address
class LiteralTable : public std::map<int,std::pair<std::pair<std::string,bool>,std::pair<int,int>>>  {
public:
	LiteralTable();
};



#endif /* LITERALTABLE_H_ */
