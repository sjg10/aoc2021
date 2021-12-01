#include <memory>
#include "Day1.h"
#include <iostream>

int main(void) {
    std::cout << "AOC2021 Start" << std::endl;
    auto day1 = std::make_unique<Day1>();
    day1->run({"../res/day1_1.txt"});
    day1.reset();

    //More days go here, with their resources from res.
    std::cout << "AOC2021 Complete" << std::endl;

    return 0;
}