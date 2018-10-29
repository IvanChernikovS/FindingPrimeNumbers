#ifndef FINDPRIMENUBRS_H
#define FINDPRIMENUBRS_H

#include <vector>
#include <thread>
//#include "myvector.h"

using namespace std;

const int ESTIMATED_MAX_NUM_OF_ITEMS = 100000;

class FindPrimeNubrs /*: public MyVector*/
{
public:
    FindPrimeNubrs(){}
    vector<int> getAllPrimeNubrs(vector<int> &myVector);
    vector<int> sieveEratosthenes(int *lowNumber, int *highNumber, vector<int> &tmpVector);
};

#endif // FINDPRIMENUBRS_H
