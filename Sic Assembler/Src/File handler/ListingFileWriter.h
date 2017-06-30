
#ifndef SICASSEMBLERV2_INTERFILEWRITER_H
#define SICASSEMBLERV2_INTERFILEWRITER_H


#include <string>
#include <fstream>
#include "../Line/AssembleyLine.h"
#include "../Line/CommentLine.h"

class ListingFileWriter {
public:
    ListingFileWriter(std::string path);
    void writeToListingFile(AssembleyLine* assembleyLine, CommentLine* commentLine);
    void writeListingFileHeader();
    void endWriter();
    void writeErrors(std::string s);
private:
    std::ofstream writer;
    int lineNumber;
    void writeCommentLine(CommentLine* line);
    void writeAssemblyLine(AssembleyLine* assembleyLine);
    void writeErrors(Error* error);
    void handleMultipleWords(AssembleyLine* assembleyLine);
    static const int SICWORDSIZE = 0x3;
    void writeOperand(AssembleyLine* assembleyLine);

};


#endif //SICASSEMBLERV2_INTERFILEWRITER_H
