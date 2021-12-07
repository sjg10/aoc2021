#include <gtest/gtest.h>
#include "Day7.h"


TEST(Day7Test, Day7Part1_2) {
    auto d = Day7();
    std::stringstream in;
    in << "16,1,2,0,4,2,7,1,2,14\n";

    auto res = d.getFuel(in);
    EXPECT_EQ(res.first, 37);
    EXPECT_EQ(res.second,168);
}