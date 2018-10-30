#include <iostream>
#include <vector>
#include "parsefile.h"
#include "findprimenubrs.h"
#include "writetofile.h"

int main()
{
    vector<int> myVector;

    cout << "Enter file path to read:" << std::endl;
    std::string fromFileName;
    std::cin >> fromFileName;

    std::string toFileName = "e://end_file.xml";

    ParseFile parsefile(fromFileName);
    parsefile.findingIntervals(myVector);

    FindPrimeNubrs fprimeNum;
    fprimeNum.getAllPrimeNubrs(myVector);

    WriteToFile wtfile(toFileName);
    wtfile.writeToXmlFile(myVector);

    std::cout << "File was saved on disk E:/, with the name: end_file.xml" << std::endl;

}
