#ifndef WRITETOFILE_H
#define WRITETOFILE_H

#include <vector>
#include <fstream>
#include "logcheck.h"

using namespace std;

class WriteToFile
{
public:
    WriteToFile(string fileName);
    void writeToXmlFile(vector<int> &myVector);
    string getWriteFileName(){return this -> toFileName;}
    void setWriteFileName(string toFileName){this -> toFileName = toFileName;}
private:
    string toFileName;
};

#endif // WRITETOFILE_H