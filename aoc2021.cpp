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
#include "Day14.h"
#include "Day15.h"
#include "Day16.h"
#include "Day17.h"
#include "Day18.h"
#include "Day19.h"
#include "Day20.h"
#include "Day21.h"
#include "Day22.h"
#include "Day23.h"
#include "Day24.h"
#include "Day25.h"
#include <iostream>


/** Register of days to run */
std::vector<std::pair<std::string, std::shared_ptr<Day>>> days = {
    {"Day1", std::make_shared<Day1>("../res/day1.txt")},
    {"Day2", std::make_shared<Day2>("../res/day2.txt")},
    {"Day3", std::make_shared<Day3>("../res/day3.txt")},
    {"Day4", std::make_shared<Day4>("../res/day4.txt")},
    {"Day5", std::make_shared<Day5>("../res/day5.txt")},
    {"Day6", std::make_shared<Day6>("../res/day6.txt")},
    {"Day7", std::make_shared<Day7>("../res/day7.txt")},
    {"Day8", std::make_shared<Day8>("../res/day8.txt")},
    {"Day9", std::make_shared<Day9>("../res/day9.txt")},
    {"Day10", std::make_shared<Day10>("../res/day10.txt")},
    {"Day11", std::make_shared<Day11>("../res/day11.txt")},
    {"Day12", std::make_shared<Day12>("../res/day12.txt")},
    {"Day13", std::make_shared<Day13>("../res/day13.txt")},
    {"Day14", std::make_shared<Day14>("../res/day14.txt")},
    {"Day15", std::make_shared<Day15>("../res/day15.txt")},
    {"Day16", std::make_shared<Day16>("../res/day16.txt")},
    {"Day17", std::make_shared<Day17>("../res/day17.txt")},
    {"Day18", std::make_shared<Day18>("../res/day18.txt")},
    {"Day19", std::make_shared<Day19>("../res/day19.txt")},
    {"Day20", std::make_shared<Day20>("../res/day20.txt")},
    {"Day21", std::make_shared<Day21>("../res/day21.txt")},
    {"Day22", std::make_shared<Day22>("../res/day22.txt")},
    {"Day23", std::make_shared<Day23>("../res/day23.txt")},
    {"Day24", std::make_shared<Day24>("../res/day24.txt")},
    {"Day25", std::make_shared<Day25>("../res/day25.txt")},
};

int main(void) {
    std::cout << "AOC2021 Start" << std::endl;
    for (auto const &day : days) {
        std::cout << day.first << " Start" << std::endl;
        day.second->runday();
    }
    std::cout << "AOC2021 Complete" << std::endl;

    return 0;
}