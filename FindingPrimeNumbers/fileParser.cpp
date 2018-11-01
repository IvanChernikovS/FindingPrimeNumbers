#include "fileParser.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std;

void negativeNumberParser(std::vector<int> &myVector);

FileParser::FileParser(string fromFileName)
{
    this -> fromFileName = fromFileName;
}

vector<int> FileParser::findingIntervals (vector<int> &myVector)
{
    //Range range;

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

    negativeNumberParser(myVector);
    zeroNumberParser(myVector);

    return myVector;
}

void FileParser::negativeNumberParser(vector<int> &myVector)
{
    for (int i = 0; i < myVector.size(); i++)
    {
        if (myVector[i] < 0)
        {
            myVector[i] = myVector[i]*(-1);
        }
        else if (myVector[i] == 0)
        {

        }
    }
}

void FileParser::zeroNumberParser(vector<int> myVector)
{
    int i = 0;
    while (i < myVector.size())
    {
        if (myVector[i] == 0)
        {
            myVector.erase(myVector.begin() + i);
        }
        else
        {
            ++i;
        }
    }
}
