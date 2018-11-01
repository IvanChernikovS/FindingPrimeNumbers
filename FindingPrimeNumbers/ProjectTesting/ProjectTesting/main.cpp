#include "fileParser.h"
#include "writetofile.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "findprimenubrs.h"

using namespace std;

bool compareVectors(vector<int> lhs, vector<int> rhs);

TEST ( Test_001, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low = 10;
    int high = 30;
    vector<int> myVector;
    vector<int> tmpVector = {11, 13, 17, 19, 23, 29};

    //Actual
    fTest.sieveEratosthenes(&low, &high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_002, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low = 1;
    int high = 1;
    vector<int> myVector;
    vector<int> tmpVector = {1};

    //Actual
    fTest.sieveEratosthenes(&low, &high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_003, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low = 0;
    int high = 0;
    vector<int> myVector;
    vector<int> tmpVector = {0};

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
    int low = 11;
    int high = 11;
    vector<int> myVector;
    vector<int> tmpVector = {11};

    //Actual
    fTest.sieveEratosthenes(&low, &high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_005, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low = 10;
    int high = 10;
    vector<int> myVector;
    vector<int> tmpVector = {10};

    //Actual
    fTest.sieveEratosthenes(&low, &high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_006, sieveEratosthenesTest )
{
    //input
    FindPrimeNubrs fTest;
    int low;
    int high;
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

TEST ( Test_007, findingIntervalsTest )
{
    //input
    FileParser fparser("e:/study/FindingPrimeNumbers/FindingPrimeNumbers/ProjectTesting/test_original_file.xml");
    vector<int> myVector;
    vector<int> tmpVector = {10, 20, 50, 100};

    //Actual
    fparser.findingIntervals(myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_008, findingIntervalsTest )
{
    //input
    FileParser fparser("e:/study/FindingPrimeNumbers/FindingPrimeNumbers/ProjectTesting/test_with_negative_numbers.xml");
    vector<int> myVector;
    vector<int> tmpVector = {10, 20, 30, 45};

    //Actual
    fparser.findingIntervals(myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_009, findingIntervalsTest )
{
    //input
    FileParser fparser("e:/study/FindingPrimeNumbers/FindingPrimeNumbers/ProjectTesting/test_without_numbers.xml");
    vector<int> myVector;
    vector<int> tmpVector = {10, 30};

    //Actual
    fparser.findingIntervals(myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_010, findingIntervalsTest )
{
    //input
    FileParser fparser("e:/study/FindingPrimeNumbers/FindingPrimeNumbers/ProjectTesting/test_without_intervals.xml");
    vector<int> myVector;
    vector<int> tmpVector;

    //Actual
    fparser.findingIntervals(myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_011, getAllPrimeNubrsTest )
{
    //input
    FindPrimeNubrs fTest;
    vector<int> myVector = {10, 20, 30, 40};
    vector<int> tmpVector = {11, 13, 17, 19, 31 ,37};

    //Actual
    fTest.getAllPrimeNubrs(myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_012, getAllPrimeNubrsTest )
{
    //input
    FindPrimeNubrs fTest;
    vector<int> myVector = {10, 40, 20, 30};
    vector<int> tmpVector = {11, 13, 17, 19, 23, 29, 31 ,37};

    //Actual
    fTest.getAllPrimeNubrs(myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_013, getAllPrimeNubrsTest )
{
    //input
    FindPrimeNubrs fTest;
    vector<int> myVector = {10, 40, 20, 50};
    vector<int> tmpVector = {11, 13, 17, 19, 23, 29, 31 ,37, 41, 43, 47};

    //Actual
    fTest.getAllPrimeNubrs(myVector);
    bool actual = compareVectors(myVector, tmpVector);


    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

bool compareVectors(vector<int> lhs, vector<int> rhs)
{
    if ( lhs.size() != rhs.size() || lhs.size() == 0 || rhs.size() == 0)
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
