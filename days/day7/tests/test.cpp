#include <gtest/gtest.h>
#include "Day7.h"


TEST(Day7Test, Day7Part1_2) {
    std::stringstream in;
    in << "16,1,2,0,4,2,7,1,2,14\n";

    auto res = Day7::getFuel(in);
    EXPECT_EQ(res.first, 37);
    EXPECT_EQ(res.second,168);
}