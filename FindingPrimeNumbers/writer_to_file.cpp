#include "writer_to_file.h"
#include <fstream>
#include <iostream>

using namespace std;

WriterToFile::WriterToFile(string toFileName)
{
    this -> toFileName = toFileName;
}

void WriterToFile::writeToXmlFile (vector<int>& primeNumbers)
{
    ofstream xmlFileName;

    if(!primeNumbers.empty())
    {

        xmlFileName.open(toFileName);

        if (xmlFileName.is_open())
        {
            xmlFileName << "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
                        << "\n" << "<root>" << "\n    " << "<primes> ";
            for (size_t i = 0; i < primeNumbers.size(); i++)
            {
                xmlFileName << primeNumbers[i] << " ";
            }

            xmlFileName << "</primes>" << "\n" << "</root>";
        }
        else
        {
            cout << "end_file wasn`t open";
        }
        xmlFileName.close();
    }
}
