#ifndef PARSEFILE_H
#define PARSEFILE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ParseFile
{
public:
    ParseFile(string fileName);
    vector<int> findingIntervals(vector<int> &myVector);
    string getFromFileName(){return this -> fromFileName;}
    void setFromFileName(string fromFileName){this -> fromFileName = fromFileName;}
private:
    string fromFileName;
};

#endif // PARSEFILE_H
