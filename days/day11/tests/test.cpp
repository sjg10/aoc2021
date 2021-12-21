#include <gtest/gtest.h>
#include "Day11.h"

TEST(Day11Test, Day11Part1_2) {
    std::stringstream in;
    in << "5483143223\n";
    in << "2745854711\n";
    in << "5264556173\n";
    in << "6141336146\n";
    in << "6357385478\n";
    in << "4167524645\n";
    in << "2176841721\n";
    in << "6882881134\n";
    in << "4846848554\n";
    in << "5283751526\n";
    auto res = Day11::getFlashes(in);
    EXPECT_EQ(res.first, 1656);
    EXPECT_EQ(res.second,195);
}