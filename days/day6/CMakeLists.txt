add_library(day6 STATIC
    src/Day6.cpp
)
target_include_directories(day6 BEFORE
    PUBLIC include
)
target_link_libraries(
  day6
  day
)

add_executable(
  day6_test
  tests/test.cpp
)

target_link_libraries(
  day6_test
  gtest gtest_main day6
)

include(GoogleTest)
gtest_discover_tests(day6_test)