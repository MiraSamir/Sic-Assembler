//
// Created by me on 5/20/2017.
//

#ifndef SICASSEMBLERV2_PROGRAM_H
#define SICASSEMBLERV2_PROGRAM_H


#include <string>

class Program {
public:
    static std::string programName;
    static int programSize;
    static int startingAddress;
    static int startingLC;
    static std::string intermediateFilePath;
    static std::string listingFilePath;
    static std::string recordsFilePath;
    static std::string asmFilePath;

};


#endif //SICASSEMBLERV2_PROGRAM_H
