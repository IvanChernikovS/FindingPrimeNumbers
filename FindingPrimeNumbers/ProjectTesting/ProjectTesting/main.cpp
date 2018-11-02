#include "file_parser.h"
#include "writer_to_file.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "primer_finder.h"

//Four files for testing are stored in the project folder "ProjectTesting".
//Compile the project and put these four files in the folder with "Makefile",
//because the paths to them in the project are relative
//or point for them the full path.

using namespace std;

bool compareVectors(vector<int> lhs, vector<int> rhs);
bool compareVectorsofRanges(vector<FileParser::Range> lhs, vector<FileParser::Range> rhs);

TEST ( Test_001, sieveEratosthenesTest )
{
    //input
    PrimerFinder fTest;
    int low = 10;
    int high = 30;
    vector<int> myVector;
    vector<int> tmpVector = {11, 13, 17, 19, 23, 29};

    //Actual
    fTest.sieveEratosthenes(low, high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_002, sieveEratosthenesTest )
{
    //input
    PrimerFinder fTest;
    int low = 1;
    int high = 1;
    vector<int> myVector;
    vector<int> tmpVector = {1};

    //Actual
    fTest.sieveEratosthenes(low, high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_003, sieveEratosthenesTest )
{
    //input
    PrimerFinder fTest;
    int low = 0;
    int high = 0;
    vector<int> myVector;
    vector<int> tmpVector = {0};

    //Actual
    fTest.sieveEratosthenes(low, high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_004, sieveEratosthenesTest )
{
    //input
    PrimerFinder fTest;
    int low = 11;
    int high = 11;
    vector<int> myVector;
    vector<int> tmpVector = {11};

    //Actual
    fTest.sieveEratosthenes(low, high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_005, sieveEratosthenesTest )
{
    //input
    PrimerFinder fTest;
    int low = 10;
    int high = 10;
    vector<int> myVector;
    vector<int> tmpVector = {10};

    //Actual
    fTest.sieveEratosthenes(low, high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_006, sieveEratosthenesTest )
{
    //input
    PrimerFinder fTest;
    int low;
    int high;
    vector<int> myVector;
    vector<int> tmpVector;

    //Actual
    fTest.sieveEratosthenes(low, high, myVector);
    bool actual = compareVectors(myVector, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_007, getIntervalsTest )
{
    //input
    FileParser fparser("./test_original_file.xml");
    vector<FileParser::Range> ranges = fparser.getIntervals();
    vector<FileParser::Range> tmpVector = {{10, 20}, {50, 100}};

    //Actual
    bool actual = compareVectorsofRanges(ranges, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_008, getIntervalsTest )
{
    //input
    FileParser fparser("./test_with_negative_numbers.xml");
    vector<FileParser::Range> ranges = fparser.getIntervals();
    vector<FileParser::Range> tmpVector = {{10, 20}, {30, 45}};

    //Actual
    bool actual = compareVectorsofRanges(ranges, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_009, getIntervalsTest )
{
    //input
    FileParser fparser("./test_without_numbers.xml");
    vector<FileParser::Range> ranges = fparser.getIntervals();
    vector<FileParser::Range> tmpVector = {{10, 30}, {3, 40}};

    //Actual
    bool actual = compareVectorsofRanges(ranges, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_010, getIntervalsTest )
{
    //input
    FileParser fparser("./test_without_intervals.xml");
    vector<FileParser::Range> ranges = fparser.getIntervals();
    vector<FileParser::Range> tmpVector;

    //Actual
    bool actual = compareVectorsofRanges(ranges, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_011, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{10, 20}, {30, 40}};
    vector<int> tmpVector = {11, 13, 17, 19, 31 ,37};
    vector<int> primeNum= fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_012, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{10, 40}, {20, 30}};
    vector<int> tmpVector = {11, 13, 17, 19, 23, 29, 31 ,37};
    vector<int> primeNum= fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_013, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{10, 40}, {20, 50}};
    vector<int> tmpVector = {11, 13, 17, 19, 23, 29, 31 ,37, 41, 43, 47};
    vector<int> primeNum= fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

int main(int argc, char *argv[])
{
    cout << "";
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

bool compareVectorsofRanges(vector<FileParser::Range> ranges, vector<FileParser::Range> tmpVector)
{
    bool actual;

    if (ranges.size() != 0 && tmpVector.size() != 0)
    {
        if (ranges.size() == tmpVector.size())
        {
            for (size_t i = 0; i < ranges.size(); i++)
            {
                if (ranges.at(i).begin == tmpVector.at(i).begin)
                {
                    actual = true;
                }
                else if (ranges.at(i).end == tmpVector.at(i).end)
                {
                    actual = true;
                }
                else
                {
                    actual = false;
                }
            }
        }
        else
        {
            actual = false;
        }
    }
    return actual;
}
