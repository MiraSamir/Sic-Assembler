#include "RecordFileWriter.h"
#include <iostream>
#include "../Program.h"

RecordFileWriter::RecordFileWriter(std::string path) {
    writer.open(path);

}

void RecordFileWriter::writeHeader() {
    writer << "H" << std::left << std::setw(6) << Program::programName
           << std::right << std::setw(6) << std::setfill('0') << std::hex
           << std::uppercase << Program::startingLC << std::setw(6)
           << std::setfill('0') << Program::programSize << std::endl;
}

void RecordFileWriter::writeLineSizeInTheObjectCode(int pos1) {
    if (pos1 != 0) {
        int pos2 = writer.tellp();
        writer.seekp(pos1);
        writer << std::setw(2) << std::setfill('0') << (pos2 - pos1 - 1) / 2;
        writer.seekp(pos2);
    }
}
void RecordFileWriter::endl() {
    writer << std::endl;
}
int RecordFileWriter::writeBody(int address, std::string objectCode) {
    writer << "T" << std::setw(6)<<std::hex <<std::uppercase<< std::setfill('0') << address;
    int pos1 = writer.tellp();
    writer << "  " << objectCode;
    return pos1;
}

void RecordFileWriter::writeString(std::string objectCode) {
    writer << objectCode;
}
void RecordFileWriter::terminateObjectCodeFile() {
    writer<< std::endl << "E" << std::setw(6) << std::setfill('0');
    writer <<Program::startingAddress;
}

void RecordFileWriter::endWriter() {
    writer.close();
}
