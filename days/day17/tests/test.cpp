#include <gtest/gtest.h>
#include "Day17.h"

TEST(Day17Test, getProbePath) {
    std::stringstream in;
    in << "target area: x=20..30, y=-10..-5\n";
    auto d = Day17();
    auto res = d.getProbePath(in);
    EXPECT_EQ(res.first, 45);
    EXPECT_EQ(res.second, 112);
}