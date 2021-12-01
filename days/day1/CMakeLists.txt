add_library(day1 STATIC
    src/Day1.cpp
)
target_include_directories(day1 BEFORE
    PUBLIC include
)
target_link_libraries(
  day1
  day
)

add_executable(
  day1_test
  tests/test.cpp
)

target_link_libraries(
  day1_test
  gtest gtest_main day1
)

include(GoogleTest)
gtest_discover_tests(day1_test)