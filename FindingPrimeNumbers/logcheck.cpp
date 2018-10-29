#include <iostream>
#include "logcheck.h"

using namespace std;

void LogCheck::logFunction(const char* messege, const char* lFile, int lLine, const char* lfunction, const char* lDate, const char* lTime)
{
    cout << "[" << lTime << " " << lDate << "] --" << messege << "-- ["
         << lLine << "] [" << lFile << " <--> " << lfunction << "];" << endl;
}
