#include <gtest/gtest.h>
#include "Day12.h"

TEST(Day12Test, Day12_a) {
    auto d = Day12();
    std::stringstream in;
    in << "start-A\n";
    in << "start-b\n";
    in << "A-c\n";
    in << "A-b\n";
    in << "b-d\n";
    in << "A-end\n";
    in << "b-end\n";
    auto res = d.getPaths(in);
    EXPECT_EQ(res.first, 10);
    EXPECT_EQ(res.second, 36);
}

TEST(Day12Test, Day12_b) {
    auto d = Day12();
    std::stringstream in;
    in << "dc-end\n";
    in << "HN-start\n";
    in << "start-kj\n";
    in << "dc-start\n";
    in << "dc-HN\n";
    in << "LN-dc\n";
    in << "HN-end\n";
    in << "kj-sa\n";
    in << "kj-HN\n";
    in << "kj-dc\n";
    auto res = d.getPaths(in);
    EXPECT_EQ(res.first, 19);
    EXPECT_EQ(res.second, 103);
}



TEST(Day12Test, Day12_c) {
    auto d = Day12();
    std::stringstream in;
    in << "fs-end\n";
    in << "he-DX\n";
    in << "fs-he\n";
    in << "start-DX\n";
    in << "pj-DX\n";
    in << "end-zg\n";
    in << "zg-sl\n";
    in << "zg-pj\n";
    in << "pj-he\n";
    in << "RW-he\n";
    in << "fs-DX\n";
    in << "pj-RW\n";
    in << "zg-RW\n";
    in << "start-pj\n";
    in << "he-WI\n";
    in << "zg-he\n";
    in << "pj-fs\n";
    in << "start-RW\n";
    auto res = d.getPaths(in);
    EXPECT_EQ(res.first, 226);
    EXPECT_EQ(res.second, 3509);
}