#include <iostream>
#include <vector>
#include "fileParser.h"
#include "findprimenubrs.h"
#include "writetofile.h"

void printVector(std::vector<int> myVector);

int main()
{
    //E:/study/FindingPrimeNumbers/original_file.xml

    std::vector<int> myVector;

    std::cout << "Enter file path to read:" << std::endl;
    std::string fromFileName;
    std::cin >> fromFileName;

    std::cout << "If negative numbers are in the file" << std::endl
              << "They will be written modulo in vector." << std::endl;

    std::string toFileName = "E:/study/FindingPrimeNumbers/end_file.xml";

    FileParser parsefile(fromFileName);
    parsefile.findingIntervals(myVector);

    if(myVector.empty())
    {
        std::cout << "No range found!";
        exit(EXIT_FAILURE);
    }

    //printVector(myVector);

    FindPrimeNubrs fprimeNum;
    fprimeNum.getAllPrimeNubrs(myVector);

    //printVector(myVector);

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
