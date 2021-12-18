#include <gtest/gtest.h>
#include "SFNumber.h"
#include "Day18.h"

class SFNumberParseTestFixture :public ::testing::TestWithParam<std::string> {
};

TEST_P(SFNumberParseTestFixture, SFParse) {
    auto parsed = SFNumber(GetParam());
    std::stringstream out;
    out << parsed;
    EXPECT_EQ(out.str(), GetParam());
}

INSTANTIATE_TEST_CASE_P(
        Day18Test,
        SFNumberParseTestFixture,
        ::testing::Values(
                "[1,2]",
                "[[1,2],3]",
                "[9,[8,7]]",
                "[[1,9],[8,5]]",
                "[[[[1,2],[3,4]],[[5,6],[7,8]]],9]",
                "[[[9,[3,8]],[[0,9],6]],[[[3,7],[4,9]],3]]",
                "[[[[1,3],[5,3]],[[1,3],[8,7]]],[[[4,9],[6,9]],[[8,2],[7,3]]]]"
        ));



TEST(Day18, Main) {
    std::stringstream in;
    in << "[[[0,[5,8]],[[1,7],[9,6]]],[[4,[1,2]],[[1,4],2]]]\n";
    in << "[[[5,[2,8]],4],[5,[[9,9],0]]]\n";
    in << "[6,[[[6,2],[5,6]],[[7,6],[4,7]]]]\n";
    in << "[[[6,[0,7]],[0,9]],[4,[9,[9,0]]]]\n";
    in << "[[[7,[6,4]],[3,[1,3]]],[[[5,5],1],9]]\n";
    in << "[[6,[[7,3],[3,2]]],[[[3,8],[5,7]],4]]\n";
    in << "[[[[5,4],[7,7]],8],[[8,3],8]]\n";
    in << "[[9,3],[[9,9],[6,[4,9]]]]\n";
    in << "[[2,[[7,7],7]],[[5,8],[[9,3],[0,2]]]]\n";
    in << "[[[[5,2],5],[8,[3,7]]],[[5,[7,5]],[4,4]]]\n";
    auto d = Day18();
    auto res = d.doMaths(in);
    EXPECT_EQ(res.first, 4140);
    EXPECT_EQ(res.second, 3993);
    
}