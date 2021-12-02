#include <gtest/gtest.h>
#include "Submarine.h"
#include "Day2.h"

TEST(Day2Test, SubmarineMove) {
    auto s = Submarine();
    s.move_basic("down 2");
    s.move_basic("forward 7");
    EXPECT_EQ(s.getLocation(), 14);
    s.move_basic("up 1");
    EXPECT_EQ(s.getLocation(), 7);
    s.move_basic("up 2");
    EXPECT_EQ(s.getLocation(), -7);
}

TEST(Day2Test, SubmarineAimed) {
    auto s = Submarine();
    s.move_aimed("down 2");
    s.move_aimed("forward 7");
    EXPECT_EQ(s.getLocation(), 98);
}

TEST(Day2Test, Day2Part1_2) {
    auto d = Day2();
    std::stringstream in;
    in << "forward 5\n";
    in << "down 5\n";
    in << "forward 8\n";
    in << "up 3\n";
    in << "down 8\n";
    in << "forward 2\n";
    auto locs = d.findLocation(in);
    EXPECT_EQ(locs.first,150);
    EXPECT_EQ(locs.second,900);
}
