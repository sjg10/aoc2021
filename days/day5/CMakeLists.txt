add_library(day5 STATIC
    src/Day5.cpp
    src/SeaMap.cpp
)
target_include_directories(day5 BEFORE
    PUBLIC include
)
target_link_libraries(
  day5
  day
)

add_executable(
  day5_test
  tests/test.cpp
)

target_link_libraries(
  day5_test
  gtest gtest_main day5
)

include(GoogleTest)
gtest_discover_tests(day5_test)