#include <gtest/gtest.h>
#include "Day13.h"

TEST(Day13Test, Day13Part1_2) {
    auto d = Day13();
    std::stringstream in;
    in << "6,10\n";
    in << "0,14\n";
    in << "9,10\n";
    in << "0,3\n";
    in << "10,4\n";
    in << "4,11\n";
    in << "6,0\n";
    in << "6,12\n";
    in << "4,1\n";
    in << "0,13\n";
    in << "10,12\n";
    in << "3,4\n";
    in << "3,0\n";
    in << "8,4\n";
    in << "1,10\n";
    in << "2,14\n";
    in << "8,10\n";
    in << "9,0\n";
    in << "\n";
    in << "fold along y=7\n";
    in << "fold along x=5\n";
    auto res = d.getFolds(in);
    EXPECT_EQ(res.first, 17);
    std::stringstream out;
    out << "\n";
    out << "#####\n";
    out << "#...#\n";
    out << "#...#\n";
    out << "#...#\n";
    out << "#####\n";
    EXPECT_EQ(res.second, out.str());

}