## Advent Of Code 2021

A CMake/C++17 based project to save Christmas 2021.

Prerequisites are `cmake` and `g++` with versions as specified in `CMakeLists.txt`

To build:

    mkdir build
    cd build
    cmake -B build
    make -C build

To run the tests run (from `build`):

    ctest

To run, add the resource files to `res/` and then run (from `build`)

    ./aoc2021
