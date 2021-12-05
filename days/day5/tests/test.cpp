#include <gtest/gtest.h>
#include "Day5.h"


TEST(Day5Test, Day5Part1_2) {
    auto d = Day5();
    std::stringstream in;
    in << "0,9 -> 5,9\n";
    in << "8,0 -> 0,8\n";
    in << "9,4 -> 3,4\n";
    in << "2,2 -> 2,1\n";
    in << "7,0 -> 7,4\n";
    in << "6,4 -> 2,0\n";
    in << "0,9 -> 2,9\n";
    in << "3,4 -> 1,4\n";
    in << "0,0 -> 8,8\n";
    in << "5,5 -> 8,2\n";

    auto res = d.getHotspots(in);
    EXPECT_EQ(res.first,5);
    EXPECT_EQ(res.second,12);
}