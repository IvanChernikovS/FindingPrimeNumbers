#include "findprimenubrs.h"
#include <iostream>
#include <thread>
#include <algorithm>

using namespace std;

void FindPrimeNubrs::sieveEratosthenes(int *lowNumber, int *highNumber, vector<int> &tmpVector)
{
//    if (*lowNumber == *highNumber)
//    {

//    }
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

    if (tmpVector.size() != 1 || tmpVector.size() != 0)
    {
        sort(tmpVector.begin(), tmpVector.end());
        tmpVector.erase(unique(tmpVector.begin(), tmpVector.end()), tmpVector.end());
    }
    else if (tmpVector.size() == 0)
    {
        exit(EXIT_FAILURE);
    }

    mtx.unlock();
}

vector<int> FindPrimeNubrs::getAllPrimeNubrs(vector<int> &myVector)
{
    //FindPrimeNubrs obj;
    if (!myVector.empty())
    {
        vector<int> tempVector;
        //tempVector.reserve(ESTIMATED_MAX_NUM_OF_ITEMS);

//        void (*foo)(int *lowNumber, int *highNumber, vector<int> &tmpVector);
//        foo = sieveEratosthenes;

        int count = myVector.size()/2;

        thread th[count];

        for (int i = 0; i < myVector.size(); i+=2)
        {
            th[i] = thread([&](){sieveEratosthenes(&myVector[i], &myVector[i+1], tempVector);});

            //th[i] = thread (&FindPrimeNubrs::sieveEratosthenes, obj, &myVector[i], &myVector[i+1], tempVector);

            th[i].join();
            //sieveEratosthenes(&myVector[i], &myVector[i+1], tempVector);
        }

//        for (int i = 0; i < count; i++)
//        {
//            //th[i] = thread([&](){sieveEratosthenes(&myVector[i], &myVector[i+1], tempVector);});

//            //th[i] = thread (&FindPrimeNubrs::sieveEratosthenes, obj, &myVector[i], &myVector[i+1], tempVector);

//            th[i].join();
//            //sieveEratosthenes(&myVector[i], &myVector[i+1], tempVector);
//        }

        myVector.clear();
        myVector.reserve(tempVector.size());

        for (int j = 0; j < tempVector.size(); j++)
        {
            myVector.push_back(tempVector[j]);
        }

        tempVector.clear();
    }
    else
    {
        cout << "Vector is empty!";
    }

    return myVector;
}

