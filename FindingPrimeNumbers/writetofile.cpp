#include "writetofile.h"

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
                    << "\n" << "<root>" << "\n    " << "<prims> ";
        for (int i = 0; i < myVector.size(); i++)
        {
            xmlFileName << myVector[i] << " ";
        }

        xmlFileName << "</primes>" << "\n" << "</root>";
    }
    else
    {
        LOG("end_file wasn`t open");
    }
    xmlFileName.close();
}

//ofstream& operator <<(ofstream &xmlFileName, WriteToFile fileName ,const vector<int> myVector)
//{
//    //ofstream fileName;

//    xmlFileName.open(fileName);

//    if (xmlFileName.is_open())
//    {
//        xmlFileName << "<?xml version=\"1.0\" encoding=\"utf-8\"?>"
//                    << "\n" << "<root>" << "\n    " << "<prims> ";
//        for (int i = 0; i < myVector.size(); i++)
//        {
//            xmlFileName << myVector[i] << " ";
//        }

//        xmlFileName << "</primes>" << "\n" << "</root>";
//    }
//    else
//    {
//        LOG("end_file wasn`t open");
//    }
//}
