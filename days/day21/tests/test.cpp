#include <gtest/gtest.h>
#include "Game.h"


TEST(Day21, Main) {
    auto g = Game(4,8);
    EXPECT_EQ(g.playGame(), 739785);
    auto res = g.playQuantumGame();
    EXPECT_EQ(res.first, 444356092776315UL);
    EXPECT_EQ(res.second, 341960390180808UL);
}
