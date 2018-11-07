#include "file_parser.h"
#include "writer_to_file.h"
#include "primer_finder.h"
#include <gtest/gtest.h>
#include <iostream>
#include <vector>

//Four files for testing are stored in the project folder "ProjectTesting".
//Compile the project and put these four files in the folder with "Makefile",
//because the paths to them in the project are relative
//or point for them the full path.

using namespace std;

bool compareVectors (vector<int> lhs, vector<int> rhs);
bool compareVectorsofRanges (vector<FileParser::Range> lhs, vector<FileParser::Range> rhs);

TEST ( Test_001, getIntervalsTest )
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

TEST ( Test_002, getIntervalsTest )
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

TEST ( Test_003, getIntervalsTest )
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

TEST ( Test_004, getIntervalsTest )
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

TEST ( Test_005, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{10, 20}, {30, 40}, {50, 55}};
    vector<int> tmpVector = {11, 13, 17, 19, 31 ,37, 53};
    vector<int> primeNum = fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_006, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{20, 10}, {40, 30}, {60, 50}};
    vector<int> tmpVector = {11, 13, 17, 19, 31 ,37, 53, 59};
    vector<int> primeNum = fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_007, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{10, 10}, {31, 31}, {100, 101}};
    vector<int> tmpVector = {31, 101};
    vector<int> primeNum = fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_008, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{10, 20}, {30, 40}, {0, 3}};
    vector<int> tmpVector = {2, 3, 11, 13, 17, 19, 31 ,37};
    vector<int> primeNum = fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_009, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges;
    vector<int> tmpVector;
    vector<int> primeNum = fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = false;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_010, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{0, 0}, {1, 1}, {2, 2}, {3, 3}};
    vector<int> tmpVector = {3};
    vector<int> primeNum = fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

TEST ( Test_011, getAllPrimeNumbersTest )
{
    //input
    PrimerFinder fTest;
    const vector<FileParser::Range> ranges = {{0, 0}, {30, 20}, {0, 10}, {11, 11}};
    vector<int> tmpVector = {2, 3, 5, 7, 11, 23, 29};
    vector<int> primeNum = fTest.getAllPrimeNumbers(ranges);

    //Actual
    bool actual = compareVectors(primeNum, tmpVector);

    //Expected
    bool expected = true;

    //Check
    ASSERT_EQ (expected, actual);
}

int main (int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

bool compareVectors (vector<int> lhs, vector<int> rhs)
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

bool compareVectorsofRanges (vector<FileParser::Range> ranges, vector<FileParser::Range> tmpVector)
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
