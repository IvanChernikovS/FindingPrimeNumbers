#include "PrimerFinder.h"
#include <iostream>
#include <thread>
#include <algorithm>
#include <math.h>

using namespace std;

void PrimerFinder::getAllPrimeNumbers(const vector<FileParser::Range>& ranges, UniquePrimeNumbersCollection& primeNumbers)
{
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
            th[i].join();
        }
}

void PrimerFinder::sieveEratosthenes(int lowNumber, int highNumber, UniquePrimeNumbersCollection& primeNumbers)
{
    if (lowNumber == highNumber)
    {
        if (!isPrimeNumber(lowNumber))
        {
            primeNumbers.addNumber(lowNumber);
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
                primeNumbers.addNumber(i);
            }
        }
    }
}

bool PrimerFinder::isPrimeNumber(int number)
{
    if (number == 1 || number == 0)
    {
        return true;
    }
    else
    {
        for (int i = 2; i < (sqrt(number) + 1); i++)
        {
            if (number % i == 0)
            {
                return true;
            }
        }
        return false;
    }
}
