#include <gtest/gtest.h>
#include "Submarine.h"
#include "Day2.h"

TEST(Day2Test, SubmarineMove) {
    auto s = Submarine();
    s.moveBasic("down 2");
    s.moveBasic("forward 7");
    EXPECT_EQ(s.getLocation(), 14);
    s.moveBasic("up 1");
    EXPECT_EQ(s.getLocation(), 7);
    s.moveBasic("up 2");
    EXPECT_EQ(s.getLocation(), -7);
}

TEST(Day2Test, SubmarineAimed) {
    auto s = Submarine();
    s.moveAimed("down 2");
    s.moveAimed("forward 7");
    EXPECT_EQ(s.getLocation(), 98);
}

TEST(Day2Test, Day2Part1_2) {
    std::stringstream in;
    in << "forward 5\n";
    in << "down 5\n";
    in << "forward 8\n";
    in << "up 3\n";
    in << "down 8\n";
    in << "forward 2\n";
    auto locs = Day2::findLocation(in);
    EXPECT_EQ(locs.first,150);
    EXPECT_EQ(locs.second,900);
}
