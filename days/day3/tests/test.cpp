#include <gtest/gtest.h>
#include "Day3.h"


TEST(Day3Test, Day3Part1) {
    std::stringstream in;
    in << "00100\n";
    in << "11110\n";
    in << "10110\n";
    in << "10111\n";
    in << "10101\n";
    in << "01111\n";
    in << "00111\n";
    in << "11100\n";
    in << "10000\n";
    in << "11001\n";
    in << "00010\n";
    in << "01010\n";
    EXPECT_EQ(Day3::getPowerConsumption(in),198);
}


TEST(Day3Test, Day3Part2) {
    std::stringstream in;
    in << "00100\n";
    in << "11110\n";
    in << "10110\n";
    in << "10111\n";
    in << "10101\n";
    in << "01111\n";
    in << "00111\n";
    in << "11100\n";
    in << "10000\n";
    in << "11001\n";
    in << "00010\n";
    in << "01010\n";
    EXPECT_EQ(Day3::getLifeSupportRating(in),230);
}
