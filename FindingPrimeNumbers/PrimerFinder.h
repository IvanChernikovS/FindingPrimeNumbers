#ifndef PRIMER_FINDER_H
#define PRIMER_FINDER_H

#include <vector>
#include "FileParser.h"
#include "UniquePrimeNumbersCollection.h"

class PrimerFinder
{
public:
    PrimerFinder(){}
    void getAllPrimeNumbers(const std::vector<FileParser::Range>& ranges, UniquePrimeNumbersCollection& primeNumbers);

private:
    void sieveEratosthenes(int lowNumber, int highNumber, UniquePrimeNumbersCollection& primeNumbers);
    bool isPrimeNumber(int num);
};

#endif // PRIMER_FINDER_H
