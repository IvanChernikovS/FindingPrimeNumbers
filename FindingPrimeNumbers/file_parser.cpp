#include "file_parser.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>

using namespace std;

FileParser::FileParser (string fromFileName)
{
    this -> fromFileName = fromFileName;
}

vector<FileParser::Range> FileParser::getIntervals ()
{
    vector<FileParser::Range> ranges;

    string line;
    bool begin_tag = false;
    bool end_tag = false;
    ifstream xmlFile(fromFileName);

    if (xmlFile.is_open())
    {
        FileParser::Range range;

        while (getline(xmlFile,line))
        {
            string tmp;

            for (int i = 0; i < line.length(); ++i)
            {

                if (line[i] == ' ' && tmp.size() == 0)
                {
                }
                else
                {
                    tmp += line[i];
                }
            }

            if (tmp == "<low>")
            {
                begin_tag = true;
                continue;
            }
            else if (tmp == "<high>")
            {
                end_tag = true;
                continue;
            }
            else if (tmp == "</low>" || tmp == "</high>")
            {
                begin_tag = false;
                end_tag = false;
                continue;
            }
            else if (true == begin_tag)
            {
                range.begin = atoi(tmp.c_str());
                begin_tag = false;
            }
            else if (true == end_tag)
            {
                range.end = atoi(tmp.c_str());
                end_tag = false;
                ranges.push_back(range);
            }
        }
    }
    else
    {
        cout << "\"original_file.xml\" wasn`t open" << endl;
    }
    xmlFile.close();

    negativeNumberParser(ranges);
    zeroNumberParser(ranges);

    return ranges;
}

void FileParser::negativeNumberParser (vector<Range>& ranges)
{
    for (auto& range: ranges)
    {
        if (range.begin < 0)
        {
            range.begin = range.begin*(-1);
        }
        else if (range.end < 0)
        {
            range.end = range.end*(-1);
        }
    }
}

void FileParser::zeroNumberParser (vector<Range>& ranges)
{
    size_t i = 0;
    while (i < ranges.size())
    {
        if (ranges.at(i).begin == 0 && ranges.at(i).end == 0)
        {
            ranges.erase(ranges.begin() + i);
        }
        else if (ranges.at(i).begin == 0 && ranges.at(i).end != 0)
        {
            ranges.at(i).begin = ranges.at(i).begin + 2;
        }
        else
        {
            ++i;
        }
    }
}
