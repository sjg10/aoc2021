#include <memory>
#include "DayExample.h"
#include <iostream>

int main(void) {
    std::cout << "AOC2021 Start" << std::endl;
    auto dayexample = std::make_unique<DayExample>(0);
    dayexample->run({});
    dayexample.reset();

    //More days, with their resources from res.
    std::cout << "AOC2021 Complete" << std::endl;

    return 0;
}