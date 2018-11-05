#include "primer_finder.h"
#include <iostream>
#include <thread>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> PrimerFinder::getAllPrimeNumbers(const vector<FileParser::Range>& ranges)
{
        vector<int> primeNumbers;
        primeNumbers.reserve(ESTIMATED_MAX_NUM_OF_ITEMS);

        size_t count = ranges.size();

        thread th[count];

        for (size_t i = 0; i < ranges.size(); ++i)
        {
            int begin = std::min(ranges.at(i).begin, ranges.at(i).end);
            int end = std::max(ranges.at(i).begin, ranges.at(i).end);
            th[i] = thread([&](){sieveEratosthenes(begin, end, primeNumbers);});

            th[i].join();
        }

    return primeNumbers;
}

void PrimerFinder::sieveEratosthenes(int lowNumber, int highNumber, vector<int>& tmpVector)
{
    if (lowNumber == highNumber)
    {
        if (!isPrimeNumber(lowNumber))
        {
            mtx.lock();

            tmpVector.push_back(lowNumber);

            mtx.unlock();
        }
    }
    else
    {
        vector<bool> prime (highNumber + 1, true);

        prime[0] = prime[1] = false;

        for (int i = 2; i * i <= highNumber; ++i)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= highNumber; j += i)
                {
                    prime[j] = false;
                }
            }
        }

        mtx.lock();

        for (int i = lowNumber; i <= highNumber; ++i)
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
}

bool PrimerFinder::isPrimeNumber(int num)
{
    if (num == 1 || num == 0)
    {
        return true;
    }
    else
    {
        for (int i = 2; i < (sqrt(num) + 1); i++)
        {
            if (num % i == 0)
            {
                return true;
            }
        }
        return false;
    }
}
