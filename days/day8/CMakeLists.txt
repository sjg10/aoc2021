add_library(day8 STATIC
    src/Day8.cpp
    src/Display.cpp
)
target_include_directories(day8 BEFORE
    PUBLIC include
)
target_link_libraries(
  day8
  day
)

add_executable(
  day8_test
  tests/test.cpp
)

target_link_libraries(
  day8_test
  gtest gtest_main day8
)

include(GoogleTest)
gtest_discover_tests(day8_test)