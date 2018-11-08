#ifndef WRITER_TO_FILE_H
#define WRITER_TO_FILE_H

#include <vector>
#include <string>
#include <iostream>
#include "UniquePrimeNumbersCollection.h"

class WriterToFile
{
public:
    WriterToFile(std::string fileName);
    void writeToXmlFile(UniquePrimeNumbersCollection& primeNum);

    std::string getWriteFileName(){return this -> toFileName;}
    void setWriteFileName(std::string toFileName){this -> toFileName = toFileName;}

private:
    std::string toFileName;
};

#endif // WRITER_TO_FILE_H
