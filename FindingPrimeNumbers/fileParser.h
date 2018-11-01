#ifndef FILEPARSER_H
#define FILEPARSER_H

#include <string>
#include <vector>
#include <iostream>

struct Range
{
    int low;
    int high;
};

class FileParser
{
public:
    FileParser(std::string fileName);
    std::vector<int> findingIntervals(std::vector<int> &myVector);
    void negativeNumberParser(std::vector<int> &myVector);
    void zeroNumberParser(std::vector<int> myVector);
    std::string getFromFileName(){return this -> fromFileName;}
    void setFromFileName(std::string fromFileName){this -> fromFileName = fromFileName;}
private:
    std::string fromFileName;
};

#endif // FILEPARSER_H
