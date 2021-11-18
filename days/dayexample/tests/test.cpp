#include <gtest/gtest.h>
#include "DayExample.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

// Demonstrate some basic assertions for new clas.
TEST(HelloTest, DayExampleUse) {
    auto day = DayExample(7);
    // Expect equality.
    EXPECT_EQ(day.getValue(), 7);
}