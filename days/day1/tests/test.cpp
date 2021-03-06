#include <gtest/gtest.h>
#include "Day1.h"
// Demonstrate some basic assertions for new clas.
TEST(Day1Test, Part1) {
    std::stringstream in;
    in << "199\n";
    in << "200\n";
    in << "208\n";
    in << "210\n";
    in << "200\n";
    in << "207\n";
    in << "240\n";
    in << "269\n";
    in << "260\n";
    in << "263\n";
    EXPECT_EQ(Day1::countIncreases(in), 7);
}

TEST(Day1Test, Part2) {
    std::stringstream in;
    in << "199\n";
    in << "200\n";
    in << "208\n";
    in << "210\n";
    in << "200\n";
    in << "207\n";
    in << "240\n";
    in << "269\n";
    in << "260\n";
    in << "263\n";
    EXPECT_EQ(Day1::countIncreases(in, 3), 5);
}