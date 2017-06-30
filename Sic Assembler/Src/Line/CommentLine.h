#ifndef SICASSEMBLERV2_COMMENTLINE_H
#define SICASSEMBLERV2_COMMENTLINE_H


#include <string>

class CommentLine {
public:
    CommentLine(std::string &s);
    std::string getComment();
private:
    std::string comment;
};
#endif //SICASSEMBLERV2_COMMENTLINE_H
