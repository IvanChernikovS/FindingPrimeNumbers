#include <iostream>
#include <vector>
#include <string>
#include "FileParser.h"
#include "PrimerFinder.h"
#include "WriterToFile.h"
#include "UniquePrimeNumbersCollection.h"

int main()
{
    std::cout << "Enter file path to read:" << std::endl;
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
    UniquePrimeNumbersCollection primeNumbers;
    primeFinder.getAllPrimeNumbers(ranges, primeNumbers);

    WriterToFile wtfile(toFileName);

    if (!primeNumbers.isEmpty())
    {
        wtfile.writeToXmlFile(primeNumbers);
    }
    else
    {
        std::cout << "No prime numbers found!" << std::endl;
    }

    std::cout << "End_file.xml file will be saved with the Makefile of project." << std::endl;
}
