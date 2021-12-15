#include <gtest/gtest.h>
#include "Day15.h"

TEST(Day15Test, Day15Part1_2) {
    auto d = Day15();
    std::stringstream in;
    in << "1163751742\n";
    in << "1381373672\n";
    in << "2136511328\n";
    in << "3694931569\n";
    in << "7463417111\n";
    in << "1319128137\n";
    in << "1359912421\n";
    in << "3125421639\n";
    in << "1293138521\n";
    in << "2311944581\n";
    auto res = d.getPaths(in);
    EXPECT_EQ(res.first, 40);
    EXPECT_EQ(res.second, 315);
}
