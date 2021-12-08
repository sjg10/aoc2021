#include <memory>
#include <map>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include <iostream>

/** Map of day name to (dayprocessor, day resources) */
std::map<std::string, std::pair<std::shared_ptr<Day>, std::vector<std::string>>> days = {
    {"Day1", {std::make_shared<Day1>(), {"../res/day1.txt"}}},
    {"Day2", {std::make_shared<Day2>(), {"../res/day2.txt"}}},
    {"Day3", {std::make_shared<Day3>(), {"../res/day3.txt"}}},
    {"Day4", {std::make_shared<Day4>(), {"../res/day4.txt"}}},
    {"Day5", {std::make_shared<Day5>(), {"../res/day5.txt"}}},
    {"Day6", {std::make_shared<Day6>(), {"../res/day6.txt"}}},
    {"Day7", {std::make_shared<Day7>(), {"../res/day7.txt"}}},
    {"Day8", {std::make_shared<Day8>(), {"../res/day8.txt"}}},
};

int main(void) {
    std::cout << "AOC2021 Start" << std::endl;
    for (auto const &day : days) {
        std::cout << day.first << " Start" << std::endl;
        day.second.first->runday(day.second.second);
    }
    std::cout << "AOC2021 Complete" << std::endl;

    return 0;
}