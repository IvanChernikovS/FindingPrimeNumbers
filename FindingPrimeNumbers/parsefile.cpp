#include "parsefile.h"
#include "logcheck.h"
#include <fstream>
#include <stdlib.h>

using namespace std;

ParseFile::ParseFile(string fromFileName)
{
    this -> fromFileName = fromFileName;
}

vector<int> ParseFile::findingIntervals(vector<int> &myVector)
{
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

            if (begin_tag)
            {
                myVector.push_back(atoi(tmp.c_str()));
            }
        }
    }
    else
    {
        LOG("origin_file wasn`t open");
    }
    xmlFile.close();

    return myVector;
}
