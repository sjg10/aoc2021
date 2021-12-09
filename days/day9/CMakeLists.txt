add_library(day9 STATIC
    src/Day9.cpp
)
target_include_directories(day9 BEFORE
    PUBLIC include
)
target_link_libraries(
  day9
  day
)

add_executable(
  day9_test
  tests/test.cpp
)

target_link_libraries(
  day9_test
  gtest gtest_main day9
)

include(GoogleTest)
gtest_discover_tests(day9_test)