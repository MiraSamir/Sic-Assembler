#include <iomanip>
#include <iostream>
#include "ListingFileWriter.h"

using namespace std;

ListingFileWriter::ListingFileWriter(std::string path) {
    writer.open(path);
    this->lineNumber = 1;
}

void ListingFileWriter::writeToListingFile(AssembleyLine *assembleyLine, CommentLine* commentLine) {

    if(assembleyLine == NULL) {
        this->writeCommentLine(commentLine);
    } else {
        this->writeAssemblyLine(assembleyLine);
    }
}

void ListingFileWriter::writeListingFileHeader() {
    writer << left << std::setw(20) << "Line no." << std::setw(20)
                 << "Address" << std::setw(20) << "Label" << std::setw(20)
                 << "Mnemonic" << std::setw(20) << "Operands" << std::setw(20)
                 << "Object Code" << std::setw(20) << "Comments" << endl << endl;
}


void ListingFileWriter::writeCommentLine(CommentLine *line) {
    writer << line->getComment() << std::endl;
}

void ListingFileWriter::writeAssemblyLine(AssembleyLine *assembleyLine) {
      writer << left << std::setw(20) << this->lineNumber
                 << setfill('0') << std::setw(4) << right << hex << uppercase
                 << assembleyLine->getAddress()->getAddress() << nouppercase << dec << setfill(' ')
                 << left << std::setw(16) << " " << std::setw(20)
                 << assembleyLine->getLabel()->getFieldStr() << std::setw(20) << assembleyLine->getMnemonic()->getFieldStr()
                 << std::setw(20);
             if(assembleyLine->getOperand()->getParsedWordOp().size() > 1) {/* hena ana multiple */
                 writer << assembleyLine->getOperand()->getParsedWordOp()[0] ;
                // << std::setw(20);
             }  else {
               writer  << assembleyLine->getOperand()->getFieldStr() ;
                 //<< std::setw(20);
             }

              if(assembleyLine->getObjectcode()->getObjCodeStrvec().size() > 0) {
                  writer  <<right << std::setw(6) << setfill('0') << assembleyLine->getObjectcode()->getObjCodeStrvec()[0]
                          <<  setfill(' ') << left
                          << std::setw(14) << " " << std::setw(20)
                          << assembleyLine->getComment()->getFieldStr() << endl;
              } else {
                  writer
                         <<  setfill(' ') << left
                         << std::setw(14) << " " << std::setw(20)
                         << assembleyLine->getComment()->getFieldStr() << endl;
              }




    this->lineNumber ++;
    this->handleMultipleWords(assembleyLine);
    this->writeErrors(assembleyLine->getError());
}


void ListingFileWriter::writeErrors(Error *error) {
    for (std::string s : error->getError())
        writer << s << std::endl;
    error->getError().clear();
}


void ListingFileWriter::endWriter() {
    writer.close();
}

void ListingFileWriter::writeErrors(std::string s) {
    writer << s << std::endl;
}

void ListingFileWriter::handleMultipleWords(AssembleyLine *assembleyLine) {
    int add = assembleyLine->getAddress()->getAddress();
  /*  std::vector<std::string>::iterator it;*/
       for(int i = 1; i < assembleyLine->getOperand()->getParsedWordOp().size(); i++) {
           add = add + this->SICWORDSIZE;
         writer  << left << std::setw(20) << this->lineNumber
                   << setfill('0') << std::setw(4) << right << hex << uppercase
                   << add << nouppercase << dec << setfill(' ')
                   << left << std::setw(16) << " " << std::setw(20)
                   << " " << std::setw(20) << assembleyLine->getMnemonic()->getFieldStr()
                   << std::setw(20) << assembleyLine->getOperand()->getParsedWordOp()[i] << right << std::setw(6)
                   << setfill('0') << assembleyLine->getObjectcode()->getObjCodeStrvec()[i] << setfill(' ') << left
                   << std::setw(14) << " " << std::setw(20) << assembleyLine->getComment()->getFieldStr()
                   << endl;



    }
   // this->writeErrors(assembleyLine->getError());*/
}


