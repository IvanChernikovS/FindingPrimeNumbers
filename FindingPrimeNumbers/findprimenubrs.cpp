#include "findprimenubrs.h"
#include <iostream>

using namespace std;

vector<int> FindPrimeNubrs::sieveEratosthenes(int *lowNumber, int *highNumber, vector<int> &tmpVector)
{
    vector<bool> prime(*highNumber + 1, true);

    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= *highNumber; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= *highNumber; j += i)
            {
                prime[j] = false;
            }
        }
    }

    mtx.lock();

    for (int i = *lowNumber; i <= *highNumber; ++i)
    {
        if (prime[i])
        {
            tmpVector.push_back(i);
        }
    }

    mtx.unlock();

    return tmpVector;
}

vector<int> FindPrimeNubrs::getAllPrimeNubrs(vector<int> &myVector)
{
    vector<int> tempVector;
    tempVector.reserve(ESTIMATED_MAX_NUM_OF_ITEMS);

    int count = myVector.size()/2;

    thread th[count];

    for (int i = 0; i < myVector.size(); i+=2)
    {
        th[i] = thread([&](){
            sieveEratosthenes(&myVector[i], &myVector[i+1], tempVector);
        });

        th[i].join();
    }

    myVector.clear();
    myVector.reserve(tempVector.size());

    for (int j = 0; j < tempVector.size(); j++)
    {
        myVector.push_back(tempVector[j]);
    }

    tempVector.clear();

    return myVector;
}

