#include <sstream>
#include "FileReader.h"
FileReader::FileReader(std::string path) {
   this->reader.open(path);
}

bool FileReader::readLine() {
    return (reader.peek() != EOF);
}

std::string FileReader::getLine() {
    std::string line;
    std::getline(this->reader, line);
    std::istringstream iss(line);
    return line;
}

void FileReader::endReader() {
    reader.close();
}
