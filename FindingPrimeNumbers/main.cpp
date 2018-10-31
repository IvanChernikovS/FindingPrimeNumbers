#include <iostream>
#include <vector>
#include "fileParser.h"
#include "findprimenubrs.h"
#include "writetofile.h"

void printVector(std::vector<int> myVector);

int main()
{
    //E:/study/FindingPrimeNumbers/origin_file.xml

    std::vector<int> myVector;

    //std::cout << "Enter file path to read:" << std::endl;
    std::string fromFileName = "E:/study/FindingPrimeNumbers/original_file.xml";
    //std::cin >> fromFileName;

    std::string toFileName = "E:/study/FindingPrimeNumbers/end_file.xml";

    ParseFile parsefile(fromFileName);
    parsefile.findingIntervals(myVector);

    //printVector(myVector);

    FindPrimeNubrs fprimeNum;
    fprimeNum.getAllPrimeNubrs(myVector);

    printVector(myVector);

    WriteToFile wtfile(toFileName);

    if (!myVector.empty())
    {
        wtfile.writeToXmlFile(myVector);
    }
    else
    {
        std::cout << "Vector is empty!";
    }
}

void printVector(std::vector<int> myVector)
{
    for (int i = 0; i < myVector.size(); i++)
    {
        std::cout << myVector[i]/*.low*/ << std::endl; //<< myVector[i].high << std::endl;
    }
}
