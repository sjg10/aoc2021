#include <gtest/gtest.h>
#include "Day10.h"

TEST(Day10Test, Day10Part1_2) {
    auto d = Day10();
    std::stringstream in;
    in << "[({(<(())[]>[[{[]{<()<>>\n";
    in << "[(()[<>])]({[<{<<[]>>(\n";
    in << "{([(<{}[<>[]}>{[]{[(<()>\n";
    in << "(((({<>}<{<{<>}{[]{[]{}\n";
    in << "[[<[([]))<([[{}[[()]]]\n";
    in << "[{[{({}]{}}([{[{{{}}([]\n";
    in << "{<[[]]>}<{[{[{[]{()[[[]\n";
    in << "[<(<(<(<{}))><([]([]()\n";
    in << "<{([([[(<>()){}]>(<<{{\n";
    in << "<{([{{}}[<[[[<>{}]]]>[]]\n";
    auto res = d.getSyntax(in);
    EXPECT_EQ(res.first, 26397);
    EXPECT_EQ(res.second,288957);
}