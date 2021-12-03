add_library(day3 STATIC
    src/Day3.cpp
)
target_include_directories(day3 BEFORE
    PUBLIC include
)
target_link_libraries(
  day3
  day
)

add_executable(
  day3_test
  tests/test.cpp
)

target_link_libraries(
  day3_test
  gtest gtest_main day3
)

include(GoogleTest)
gtest_discover_tests(day3_test)