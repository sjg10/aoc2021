#include <gtest/gtest.h>
#include "Day6.h"


TEST(Day6Test, Day6Part1_2) {
    auto d = Day6();
    std::stringstream in;
    in << "3,4,3,1,2\n";

    auto res = d.getFish(in);
    EXPECT_EQ(res.first, 5934);
    EXPECT_EQ(res.second,26984457539UL);
}