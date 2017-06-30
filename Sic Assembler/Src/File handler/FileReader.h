#ifndef SICASSEMBLERV2_FILEREADER_H
#define SICASSEMBLERV2_FILEREADER_H


#include <string>
#include <fstream>

class FileReader {
public:
    FileReader(std::string path);
    bool readLine();
    std::string getLine();
    void endReader();
private:
    std::ifstream reader;
};


#endif //SICASSEMBLERV2_FILEREADER_H
