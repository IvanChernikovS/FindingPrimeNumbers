#include "fileParser.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std;

ParseFile::ParseFile(string fromFileName)
{
    this -> fromFileName = fromFileName;
}

vector<int> ParseFile::findingIntervals (vector<int> &myVector)
{
    //Range range;
//    vector<int> lowRange;
//    vector<int> highRange;

    string line;
    bool begin_tag = false;
    ifstream xmlFile(fromFileName);

    if (xmlFile.is_open())
    {
        while (getline(xmlFile,line))
        {
            string tmp;

            for (int i = 0; i < line.length(); i++)
            {

                if (line[i] == ' ' && tmp.size() == 0)
                {
                }
                else
                {
                    tmp += line[i];
                }
            }

            if (tmp == "<low>" || tmp == "<high>")
            {
                begin_tag = true;
                continue;
            }
            else if (tmp == "</low>" || tmp == "</high>")
            {
                begin_tag = false;
            }

            if (begin_tag /*&& tmp == "<low>"*/)
            {
                myVector.push_back(atoi(tmp.c_str()));
                //lowRange.push_back(atoi(tmp.c_str()));
                //range.low = atoi(tmp.c_str());
            }
//            else if (begin_tag && tmp == "<high>")
//            {
//                range.high = atoi(tmp.c_str());
//                myVector.push_back(range);
//                highRange.push_back(atoi(tmp.c_str()));
//            }
//            myVector.push_back(range);
        }
    }
    else
    {
        cout << "original_file wasn`t open";
    }
    xmlFile.close();

    if(myVector.empty())
    {
        cout << "No range found!";
        exit(EXIT_FAILURE);
    }

    return myVector;
}
