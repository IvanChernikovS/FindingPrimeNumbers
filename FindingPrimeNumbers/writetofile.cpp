#include "writetofile.h"
#include <fstream>
#include <iostream>

using namespace std;

WriteToFile::WriteToFile(string toFileName)
{
    this -> toFileName = toFileName;
}

void WriteToFile::writeToXmlFile (vector<int> &myVector)
{
    ofstream xmlFileName;

    xmlFileName.open(toFileName);

    if (xmlFileName.is_open())
    {
        xmlFileName << "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
                    << "\n" << "<root>" << "\n    " << "<primes> ";
        for (int i = 0; i < myVector.size(); i++)
        {
            xmlFileName << myVector[i] << " ";
        }

        xmlFileName << "</primes>" << "\n" << "</root>";
    }
    else
    {
        cout << "end_file wasn`t open";
    }
    xmlFileName.close();
}
