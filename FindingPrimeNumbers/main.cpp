#include <iostream>
#include <vector>
#include "file_parser.h"
#include "primer_finder.h"
#include "writer_to_file.h"

int main()
{
    std::cout << "Enter file path to read:" << std::endl; //E:/study/FindingPrimeNumbers/original_file.xml
    std::string fromFileName;
    std::cin >> fromFileName;

    std::cout << "\n" << "All zero intervals will be deleted." << "\n" << std::endl;

    std::string toFileName = "./end_file.xml";

    FileParser fileParser(fromFileName);
    std::vector<FileParser::Range> ranges = fileParser.getIntervals();

    if(ranges.empty())
    {
        std::cout << "No range found!";
        exit(EXIT_FAILURE);
    }

    PrimerFinder primeFinder;
    std::vector<int> primeNumbers = primeFinder.getAllPrimeNumbers(ranges);

    WriterToFile wtfile(toFileName);

    if (!primeNumbers.empty())
    {
        wtfile.writeToXmlFile(primeNumbers);
    }
    else
    {
        std::cout << "No prime numbers found!" << std::endl;
    }

    std::cout << "\"End_file.xml\" file will be saved with the Makefile of project." << std::endl;
}
