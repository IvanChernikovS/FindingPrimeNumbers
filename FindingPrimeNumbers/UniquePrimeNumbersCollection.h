#ifndef UNIQUE_PRIME_NUMBERS_COLLECTION_H
#define UNIQUE_PRIME_NUMBERS_COLLECTION_H

#include <set>
#include <mutex>
#include <vector>

class UniquePrimeNumbersCollection
{
public:
    UniquePrimeNumbersCollection(){}

    void addNumber(int number);
    bool isEmpty();
    std::vector<int> getPrimeNumbers();

private:
    std::set<int> primes;
    std::mutex mutex;
};

#endif // UNIQUE_PRIME_NUMBERS_COLLECTION_H
