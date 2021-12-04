add_library(day4 STATIC
    src/Day4.cpp
    src/BingoCard.cpp
)
target_include_directories(day4 BEFORE
    PUBLIC include
)
target_link_libraries(
  day4
  day
)

add_executable(
  day4_test
  tests/test.cpp
)

target_link_libraries(
  day4_test
  gtest gtest_main day4
)

include(GoogleTest)
gtest_discover_tests(day4_test)