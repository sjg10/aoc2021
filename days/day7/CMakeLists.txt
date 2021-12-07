add_library(day7 STATIC
    src/Day7.cpp
)
target_include_directories(day7 BEFORE
    PUBLIC include
)
target_link_libraries(
  day7
  day
)

add_executable(
  day7_test
  tests/test.cpp
)

target_link_libraries(
  day7_test
  gtest gtest_main day7
)

include(GoogleTest)
gtest_discover_tests(day7_test)