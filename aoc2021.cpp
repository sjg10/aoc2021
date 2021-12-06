#include <memory>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include <iostream>

int main(void) {
    std::cout << "AOC2021 Start" << std::endl;
    auto day1 = std::make_unique<Day1>();
    day1->run({"../res/day1.txt"});
    day1.reset();

    auto day2 = std::make_unique<Day2>();
    day2->run({"../res/day2.txt"});
    day2.reset();

    auto day3 = std::make_unique<Day3>();
    day3->run({"../res/day3.txt"});
    day3.reset();

    auto day4 = std::make_unique<Day4>();
    day4->run({"../res/day4.txt"});
    day4.reset();

    auto day5 = std::make_unique<Day5>();
    day5->run({"../res/day5.txt"});
    day5.reset();

    auto day6 = std::make_unique<Day6>();
    day6->run({"../res/day6.txt"});
    day6.reset();
    //More days go here, with their resources from res.
    std::cout << "AOC2021 Complete" << std::endl;

    return 0;
}