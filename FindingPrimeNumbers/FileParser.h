#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <string>
#include <vector>

class FileParser
{
public:
    struct Range
    {
        int begin;
        int end;
    };

public:
    FileParser(std::string fileName);
    std::vector<Range> getIntervals();

    std::string getFromFileName(){return this -> fromFileName;}
    void setFromFileName(std::string fromFileName){this -> fromFileName = fromFileName;}

private:
    void negativeNumberParser(std::vector<Range>& ranges);
    void zeroNumberParser(std::vector<Range>& ranges);

    std::string fromFileName;
};

#endif // FILE_PARSER_H
