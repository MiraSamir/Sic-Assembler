#include "../Line/CommentLine.h"

CommentLine::CommentLine(std::string &s) {
    this->comment = s;
}

std::string CommentLine::getComment() {
    return this->comment;
}
