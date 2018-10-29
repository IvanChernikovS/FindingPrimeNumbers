#include <iostream>
#include <vector>
#include "parsefile.h"
#include "findprimenubrs.h"
#include "writetofile.h"

void print(vector<int> &myVector);

int main()
{
    vector<int> myVector;
    std::string fromFileName = "e:/study/FindingPrimeNumbers/origin_file.xml";
    std::string toFileName = "e:/study/FindingPrimeNumbers/end_file.xml";

    ParseFile parsefile(fromFileName);
    parsefile.findingIntervals(myVector);

    FindPrimeNubrs fprimeNum;
    fprimeNum.getAllPrimeNubrs(myVector);

    WriteToFile wtfile(toFileName);
    wtfile.writeToXmlFile(myVector);
}

void print(vector<int> &myVector)
{
    for(int i = 0; i < myVector.size(); i++)
    {
        std::cout << myVector[i] << endl;
    }
}
