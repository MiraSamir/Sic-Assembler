//
// Created by me on 5/19/2017.
//

#ifndef SICASSEMBLERV2_OPTABLE_H
#define SICASSEMBLERV2_OPTABLE_H


#include <string>
#include <unordered_map>

class OpTable : public std::unordered_map<std::string, std::pair < int,int>> {
public:
OpTable();
};

#endif //SICASSEMBLERV2_OPTABLE_H
