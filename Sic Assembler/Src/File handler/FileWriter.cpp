#include <iomanip>
#include "../File handler/FileWriter.h"
#include "../Line/CommentLine.h"
#include <iostream>

FileWriter::FileWriter(std::string path) {
    writer.open(path);
    this->lineNumber = 1;
}

void FileWriter::writeToIntermediateFile(AssembleyLine *assembleyLine, CommentLine* commentLine) {
    if(assembleyLine == NULL) {
        this->writeCommentLine(commentLine);
    } else {
        this->writeAssemblyLine(assembleyLine);
    }
}

void FileWriter::writeIntermediateFileHeader() {
    writer << std::left << std::setw(20) << "Line no."
           << std::setw(20) << "Address" << std::setw(20) << "Label"
           << std::setw(20) << "Mnemonic" << std::setw(20) << "Operands"
           << std::setw(20) << "Comments" << std::endl << std::endl;
}
void FileWriter::writeLiteralLine(std::vector<std::string> vector) {

    writer << std::left << std::setw(20) << this->lineNumber
           << std::setfill('0') << std::setw(4) << std::right << std::hex << std::uppercase
           << vector[0] << std::nouppercase << std::dec << std::setfill(' ')
           << std::left << std::setw(16) << " " << std::setw(20)
           << vector[1] << std::setw(20) << vector[2] << std::endl;
    this->lineNumber++;
}


void FileWriter::writeCommentLine(CommentLine *line) {
    writer << line->getComment() << std::endl;
}

void FileWriter::writeAssemblyLine(AssembleyLine *assembleyLine) {



    writer << std::left << std::setw(20) << this->lineNumber
           << std::setfill('0') << std::setw(4) << std::right << std::hex << std::uppercase
           << assembleyLine->getAddress()->getAddress() << std::nouppercase << std::dec << std::setfill(' ')
           << std::left << std::setw(16) << " " << std::setw(20)
           << assembleyLine->getLabel()->getFieldStr() << std::setw(20) << assembleyLine->getMnemonic()->getFieldStr()
           << std::setw(20) << assembleyLine->getOperand()->getFieldStr()<< std::setw(20)
           << assembleyLine->getComment()->getFieldStr()<< std::endl;
    this->writeErrors(assembleyLine->getError());
    this->lineNumber ++;
}


void FileWriter::writeErrors(Error *error) {
    for (std::string s : error->getError())
        writer << s << std::endl;
    error->getError().clear();
}


void FileWriter::endWriter() {
    writer.close();
}

void FileWriter::writeErrors(std::string s) {
    writer << s << std::endl;
}



