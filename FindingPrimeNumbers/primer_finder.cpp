#include "primer_finder.h"
#include <iostream>
#include <thread>
#include <algorithm>
#include <math.h>

using namespace std;

vector<int> PrimerFinder::getAllPrimeNumbers (const vector<FileParser::Range>& ranges)
{
        vector<int> primeNumbers;
        primeNumbers.reserve(ESTIMATED_MAX_NUM_OF_ITEMS);

        size_t count = ranges.size();

        thread th[count];

        for (size_t i = 0; i < ranges.size(); ++i)
        {
            int begin = std::min(ranges.at(i).begin, ranges.at(i).end);
            int end = std::max(ranges.at(i).begin, ranges.at(i).end);

            th[i] = thread(&PrimerFinder::sieveEratosthenes, this, begin, end, ref(primeNumbers));
        }

        for (size_t i = 0; i < ranges.size(); ++i)
        {
            if (th[i].joinable())
            {
                th[i].join();
            }
        }

        if (primeNumbers.size() != 1 || primeNumbers.size() != 0)
        {
            primeNumbers = vectorCheck(primeNumbers);
        }
        else if (primeNumbers.size() == 0)
        {
            exit(EXIT_FAILURE);
        }

    return primeNumbers;
}

void PrimerFinder::sieveEratosthenes (int lowNumber, int highNumber, vector<int>& tmpVector)
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

        for (int i = lowNumber; i <= highNumber; ++i)
        {
            if (prime[i])
            {
                mtx.lock();

                tmpVector.push_back(i);

                mtx.unlock();
            }
        }
    }
}

bool PrimerFinder::isPrimeNumber (int num)
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

vector<int> PrimerFinder::vectorCheck (vector<int> tmpVector)
{
        sort(tmpVector.begin(), tmpVector.end());
        tmpVector.erase(unique(tmpVector.begin(), tmpVector.end()), tmpVector.end());

    return tmpVector;
}
