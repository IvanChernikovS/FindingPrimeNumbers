#ifndef PRIMER_FINDER_H
#define PRIMER_FINDER_H

#include <iostream>
#include <vector>
#include <mutex>
#include "file_parser.h"

const int ESTIMATED_MAX_NUM_OF_ITEMS = 10000;

class PrimerFinder
{
public:
    explicit PrimerFinder(){}
    std::vector<int> getAllPrimeNumbers(const std::vector<FileParser::Range>& ranges);
    void sieveEratosthenes(int lowNumber, int highNumber, std::vector<int>& tmpVector);
    bool isPrimeNumber(int num);
    std::mutex mtx;
};

#endif // PRIMER_FINDER_H
