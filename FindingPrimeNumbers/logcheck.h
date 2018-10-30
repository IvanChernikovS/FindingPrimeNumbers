#ifndef LOGCHECK_H
#define LOGCHECK_H

#include <iostream>

class LogCheck;
#define LOG(messege) LogCheck::logFunction(messege, __FILE__, __LINE__, __FUNCTION__, __DATE__, __TIME__ )

class LogCheck
{
public:
    LogCheck(){}
    static void logFunction(const char* messege, const char* lFile, int lLine, const char* lfunction, const char* lDate, const char* lTime);
};

#endif // LOGCHECK_H
