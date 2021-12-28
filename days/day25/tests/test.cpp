#include <gtest/gtest.h>
#include "CucumberHerds.h"

TEST(Day25, Main1) {
    std::stringstream in;
    in << "v...>>.vv>\n";
    in << ".vv>>.vv..\n";
    in << ">>.>v>...v\n";
    in << ">>v>>.>.v.\n";
    in << "v>v.vv.v..\n";
    in << ">.>>..v...\n";
    in << ".vv..>.>v.\n";
    in << "v.v..>>v.v\n";
    in << "....v..v.>\n";

    auto b = CucumberHerds(in);
    auto res = b.getMinSteps();
    EXPECT_EQ(res, 58);
}
