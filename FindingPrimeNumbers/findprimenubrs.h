#ifndef FINDPRIMENUBRS_H
#define FINDPRIMENUBRS_H

#include <iostream>
#include <vector>
#include <mutex>

const int ESTIMATED_MAX_NUM_OF_ITEMS = 10000;

class FindPrimeNubrs
{
public:
    FindPrimeNubrs(){}
    std::vector<int> getAllPrimeNubrs(std::vector<int> &myVector);
    void sieveEratosthenes(int *lowNumber, int *highNumber, std::vector<int> &tmpVector);
    //std::mutex mtx;
};

#endif // FINDPRIMENUBRS_H
