

#ifndef SICASSEMBLERV2_UTILITY_H
#define SICASSEMBLERV2_UTILITY_H


#include <string>

class Utility {
public:
    static bool isLettersOnly(std::string &s);
    static bool isHex(std::string &s);
    static bool isWhiteSpacesOnly(std::string &s);
    static std::string to_upper(std::string s);
    static bool isInteger(std::string &s);
    static bool isComment(std::string &s);
    static void eraseTrailingSpace(std::string &s);
    static void eraseLeadingSpace(std::string &s);


};


#endif //SICASSEMBLERV2_UTILITY_H
