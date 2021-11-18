add_library(dayexample STATIC
    src/DayExample.cpp
)
target_include_directories(dayexample BEFORE
    PUBLIC include
)
target_link_libraries(
  dayexample
  day
)

add_executable(
  hello_test
  tests/test.cpp
)

target_link_libraries(
  hello_test
  gtest gtest_main dayexample
)

include(GoogleTest)
gtest_discover_tests(hello_test)