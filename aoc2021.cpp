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
#include "Day9.h"
#include "Day10.h"
#include "Day11.h"
#include "Day12.h"
#include "Day13.h"
#include <iostream>
//Collected info for a day
struct DayDesc {
    std::string name;
    std::shared_ptr<Day> day;
    std::vector<std::string> res_files;
} ;
/** Register of days to run */
std::vector<DayDesc> days = {
    {"Day1", std::make_shared<Day1>(), {"../res/day1.txt"}},
    {"Day2", std::make_shared<Day2>(), {"../res/day2.txt"}},
    {"Day3", std::make_shared<Day3>(), {"../res/day3.txt"}},
    {"Day4", std::make_shared<Day4>(), {"../res/day4.txt"}},
    {"Day5", std::make_shared<Day5>(), {"../res/day5.txt"}},
    {"Day6", std::make_shared<Day6>(), {"../res/day6.txt"}},
    {"Day7", std::make_shared<Day7>(), {"../res/day7.txt"}},
    {"Day8", std::make_shared<Day8>(), {"../res/day8.txt"}},
    {"Day9", std::make_shared<Day9>(), {"../res/day9.txt"}},
    {"Day10", std::make_shared<Day10>(), {"../res/day10.txt"}},
    {"Day11", std::make_shared<Day11>(), {"../res/day11.txt"}},
    {"Day12", std::make_shared<Day12>(), {"../res/day12.txt"}},
    {"Day13", std::make_shared<Day13>(), {"../res/day13.txt"}},
};

int main(void) {
    std::cout << "AOC2021 Start" << std::endl;
    for (auto const &day : days) {
        std::cout << day.name << " Start" << std::endl;
        day.day->runday(day.res_files);
    }
    std::cout << "AOC2021 Complete" << std::endl;

    return 0;
}