#include "UniquePrimeNumbersCollection.h"
#include <iostream>

using namespace std;

void UniquePrimeNumbersCollection::addNumber(int number)
{
    lock_guard<std::mutex> locker(mutex);

    primes.emplace(number);
}

bool UniquePrimeNumbersCollection::isEmpty()
{
    lock_guard<std::mutex> locker(mutex);

    return primes.empty();
}

vector<int> UniquePrimeNumbersCollection::getPrimeNumbers()
{
    vector<int> primeNumbers;

        for (auto number: primes)
        {
            primeNumbers.push_back(number);
        }

    return primeNumbers;
}
