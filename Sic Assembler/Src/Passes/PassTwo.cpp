#include <fstream>
#include <iostream>
#include "../Tables/OpTable.h"
#include "../Tables/SymbolTable.h"
#include "PassTwo.h"
#include "../Parser/InterFileParser.h"
#include "../File handler/FileReader.h"
#include "../File handler/FileWriter.h"
#include "../Program.h"
#include "../File handler/ListingFileWriter.h"
#include "../Parser/ListingFileParser.h"
#include "../Utility.h"
#include "../File handler/RecordFileWriter.h"

PassTwo::PassTwo(OpTable *op, SymbolTable *sym, DirectiveTable* directiveTable,
                 LiteralTable* literalTable) {
    this->opTable = op;
    this->symbolTable = sym;
    this->directiveTable = directiveTable;
    this->succeed = true;
    this->literalTable = literalTable;
    this->parser = new InterFileParser(op, directiveTable, sym, literalTable);
}

bool PassTwo::generateListingFile() {
    FileReader* reader = new FileReader(Program::intermediateFilePath);
    AssembleyLine *assemblyLine;
    ListingFileWriter* writer = new ListingFileWriter(
            this->evaluateListingFilePath(Program::intermediateFilePath));
    writer->writeListingFileHeader();
    reader->getLine(); /* Escaping header*/
    while (reader->readLine()) {
        std::string line = reader->getLine();
        if (line.empty())
            continue;
        else if (Utility::isComment(line))
            writer->writeToListingFile(NULL, new CommentLine(line));
        else {
            assemblyLine = this->parser->parse(line);
            assemblyLine->getObjectcode()->generateObjectCode(this->opTable,
                                                              this->symbolTable, assemblyLine->getMnemonic(),
                                                              assemblyLine->getOperand(), assemblyLine->getError(),
                                                              assemblyLine->getAddress()->getAddress());

            if ((assemblyLine->getError()->getError().size() > 1)
                && this->succeed) {
                this->succeed = false;
            }
            writer->writeToListingFile(assemblyLine, NULL);
        }
    }
    writer->endWriter();
    reader->endReader();
    return this->succeed;
}

string PassTwo::evaluateListingFilePath(std::string path) {
    size_t lastIndex = path.find_last_of(".");
    string rawname = path.substr(0, lastIndex - 1);
    std::string listExtension = ".list";
    this->listingFilePath = rawname + listExtension;
    Program::listingFilePath = this->listingFilePath;
    return this->listingFilePath;
}
void PassTwo::generateObjectCodeFile() {
    FileReader* reader = new FileReader(Program::listingFilePath);
    AssembleyLine *assemblyLine;
    ListingFileParser *parser = new ListingFileParser(this->opTable, this->directiveTable, this->symbolTable, this->literalTable);
    RecordFileWriter* writer = new RecordFileWriter(this->evaluateRecordFilePath(Program::listingFilePath));
    writer->writeHeader();
    int counter = 0, pos1 = 0;
    while (++counter < 3)
        reader->getLine();
    counter = 0;
    while (reader->readLine()) {
        std::string line = reader->getLine();
        if (line.empty() || (Utility::isComment(line))) continue;
        assemblyLine = parser->parse(line);
        string objectCode = assemblyLine->getObjectcode()->getObjCodeStr();
        if (objectCode.empty()) {
            if (assemblyLine->getMnemonic()->isRESDirective())
                counter = 0;
            continue;
        } else if ((counter + objectCode.size() > this->recordLength) || counter == 0) {
            writer->writeLineSizeInTheObjectCode(pos1);
            if (pos1 != 0)  writer->endl();
            pos1 = writer->writeBody(assemblyLine->getAddress()->getAddress(), objectCode);
            counter = 9 + objectCode.size();
        } else {
            writer->writeString(objectCode);
            counter += objectCode.size();
        }
    }
    writer->writeLineSizeInTheObjectCode(pos1);
    writer->terminateObjectCodeFile();
    writer->endWriter();
    reader->endReader();
}
string PassTwo::evaluateRecordFilePath(std::string path) {
    size_t lastIndex = path.find_last_of(".");
    string rawname = path.substr(0, lastIndex);
    std::string listExtension = ".obj";
    Program::recordsFilePath = rawname + listExtension;
    return Program::recordsFilePath;
}
