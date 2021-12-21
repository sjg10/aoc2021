#include <gtest/gtest.h>
#include "Day4.h"


TEST(Day4Test, Day4Part1_2) {
    std::stringstream in;
    in << "7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1\n";
    in << "\n";
    in << "22 13 17 11  0\n";
    in << " 8  2 23  4 24\n";
    in << "21  9 14 16  7\n";
    in << " 6 10  3 18  5\n";
    in << " 1 12 20 15 19\n";
    in << "\n";
    in << " 3 15  0  2 22\n";
    in << " 9 18 13 17  5\n";
    in << "19  8  7 25 23\n";
    in << "20 11 10 24  4\n";
    in << "14 21 16 12  6\n";
    in << "\n";
    in << "14 21 17 24  4\n";
    in << "10 16 15  9 19\n";
    in << "18  8 23 26 20\n";
    in << "22 11 13  6  5\n";
    in << " 2  0 12  3  7\n";
    auto res = Day4::playBingo(in);
    EXPECT_EQ(res.first,4512);
    EXPECT_EQ(res.second,1924);
}