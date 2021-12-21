#include <gtest/gtest.h>
#include "Day17.h"

TEST(Day17Test, getProbePath) {
    std::stringstream in;
    in << "target area: x=20..30, y=-10..-5\n";
    auto res = Day17::getProbePath(in);
    EXPECT_EQ(res.first, 45);
    EXPECT_EQ(res.second, 112);
}