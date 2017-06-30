
#ifndef RECORDFILEWRITER_H_
#define RECORDFILEWRITER_H_
#include <fstream>
#include <iomanip>
class RecordFileWriter {
public:
    RecordFileWriter(std::string path);
    void writeHeader();
    void writeLineSizeInTheObjectCode(int pos1);
    void endl();
    int writeBody(int address,std::string objectCode);
    void writeString(std::string objectCode);
    void terminateObjectCodeFile();
    void endWriter();


private:
    std::ofstream writer;
};

#endif /* RECORDFILEWRITER_H_ */
