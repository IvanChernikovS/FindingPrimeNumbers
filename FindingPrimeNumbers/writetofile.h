#ifndef WRITETOFILE_H
#define WRITETOFILE_H

#include <vector>
#include <string>
#include <iostream>

class WriteToFile
{
public:
    WriteToFile(std::string fileName);
    void writeToXmlFile(std::vector<int> &myVector);
    std::string getWriteFileName(){return this -> toFileName;}
    void setWriteFileName(std::string toFileName){this -> toFileName = toFileName;}
private:
    std::string toFileName;
};

#endif // WRITETOFILE_H
