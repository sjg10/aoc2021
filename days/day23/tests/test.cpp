#include <gtest/gtest.h>
#include "Burrow.h"

TEST(Day23, Main1) {
    std::stringstream in;
    in << "#############\n";
    in << "#...........#\n";
    in << "###B#C#B#D###\n";
    in << "  #A#D#C#A#\n";
    in << "  #########\n";
    auto b = Burrow(in);
    auto res = b.getMinEnergy();
    EXPECT_EQ(res.first, 12521);
    EXPECT_EQ(res.second, 44169);
}
