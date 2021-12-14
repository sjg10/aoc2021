#include <gtest/gtest.h>
#include "Day14.h"

TEST(Day14Test, Day14_1) {
    auto d = Day14();
    std::stringstream in;;
    in << "NNCB\n";
    in << "\n";
    in << "CH -> B\n";
    in << "HH -> N\n";
    in << "CB -> H\n";
    in << "NH -> C\n";
    in << "HB -> C\n";
    in << "HC -> B\n";
    in << "HN -> C\n";
    in << "NN -> C\n";
    in << "BH -> H\n";
    in << "NC -> B\n";
    in << "NB -> B\n";
    in << "BN -> B\n";
    in << "BB -> N\n";
    in << "BC -> B\n";
    in << "CC -> N\n";
    in << "CN -> C\n";
    auto res = d.getPolymer(in);
    EXPECT_EQ(res.first, 1588);
    EXPECT_EQ(res.second, 2188189693529);
}
