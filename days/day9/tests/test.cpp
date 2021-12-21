#include <gtest/gtest.h>
#include "Day9.h"

TEST(Day9Test, Day9Part1_2) {
    std::stringstream in;
    in << "2199943210\n";
    in << "3987894921\n";
    in << "9856789892\n";
    in << "8767896789\n";
    in << "9899965678\n";
    auto res = Day9::getDanger(in);
    EXPECT_EQ(res.first, 15);
    EXPECT_EQ(res.second,1134);
}