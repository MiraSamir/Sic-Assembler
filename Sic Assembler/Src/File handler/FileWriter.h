#ifndef SICASSEMBLERV2_FILEWRITER_H
#define SICASSEMBLERV2_FILEWRITER_H


#include <string>
#include <fstream>
#include "../Line/AssembleyLine.h"
#include "../Line/CommentLine.h"

class FileWriter {
public:
    FileWriter(std::string path);
    void writeToIntermediateFile(AssembleyLine* assembleyLine, CommentLine* commentLine);
    void writeIntermediateFileHeader();
    void endWriter();
    void writeErrors(std::string s);
    void writeLiteralLine(std::vector<std::string> vector);
private:
    std::ofstream writer;
    int lineNumber;
    void writeCommentLine(CommentLine* line);
    void writeAssemblyLine(AssembleyLine* assembleyLine);
    void writeErrors(Error* error);


};


#endif //SICASSEMBLERV2_FILEWRITER_H
