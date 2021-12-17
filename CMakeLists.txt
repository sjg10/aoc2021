cmake_minimum_required(VERSION 3.14)
project(aoc2021)

# Get deps folder
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/deps/)

# Setup Compiler
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)


# enable tests
include(CTest)
enable_testing()
find_package(GoogleTest REQUIRED)

# Add subdirectories
add_subdirectory(days)
add_subdirectory(common)

# Add main executable
add_executable(aoc2021
    aoc2021.cpp)
target_link_libraries(
    aoc2021
    day1
    day2
    day3
    day4
    day5
    day6
    day7
    day8
    day9
    day10
    day11
    day12
    day13
    day14
    day15
    day16
    day17
    )