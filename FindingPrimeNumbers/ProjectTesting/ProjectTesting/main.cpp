#include "fileParser.h"
#include "writetofile.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "findprimenubrs.h"

using namespace std;

bool compareVectors(vector<int> lhs, vector<int> rhs)
{
    if ( lhs.size() != rhs.size() )
    {
       return false;
    }
    else
    {
        std::sort(lhs.begin(), lhs.end());
        std::sort(rhs.begin(), rhs.end());
        return (lhs == rhs);
    }
}

TEST ( Test_001, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low = 10;
    int high = 30;
    vector<int> myVector;
    vector<int> tmpVector = {17, 19, 23};

    //Actual
    fTest.sieveEratosthenes(&low, &high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);

}

TEST ( Test_002, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low = 10.2;
    int high = 20.2;
    vector<int> myVector;
    vector<int> tmpVector = {11, 13, 17, 19};

    //Actual
    fTest.sieveEratosthenes(&low, &high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_003, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low = 10;
    int high = 20;
    vector<int> myVector;
    vector<int> tmpVector;

    //Actual
    fTest.sieveEratosthenes(&low, &high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);

}

TEST ( Test_004, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low = 1;
    int high = 1;
    vector<int> myVector;

    //Actual
    fTest.sieveEratosthenes(&low, &high, myVector);
    bool actual = compareVectors(myVector, myVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);

}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
