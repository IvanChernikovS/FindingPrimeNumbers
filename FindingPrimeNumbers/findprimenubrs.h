#ifndef FINDPRIMENUBRS_H
#define FINDPRIMENUBRS_H

#include <vector>
#include <thread>
#include <mutex>
//#include "myvector.h"

using namespace std;

const int ESTIMATED_MAX_NUM_OF_ITEMS = 10000;

class FindPrimeNubrs
{
public:
    FindPrimeNubrs(){}
    vector<int> getAllPrimeNubrs(vector<int> &myVector);
    vector<int> sieveEratosthenes(int *lowNumber, int *highNumber, vector<int> &tmpVector);
    mutex mtx;
};

#endif // FINDPRIMENUBRS_H
