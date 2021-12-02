add_library(day2 STATIC
    src/Day2.cpp
    src/Submarine.cpp
)
target_include_directories(day2 BEFORE
    PUBLIC include
)
target_link_libraries(
  day2
  day
)

add_executable(
  day2_test
  tests/test.cpp
)

target_link_libraries(
  day2_test
  gtest gtest_main day2
)

include(GoogleTest)
gtest_discover_tests(day2_test)