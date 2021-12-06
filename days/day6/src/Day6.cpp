#include <iostream>
#include <fstream>
#include <numeric>
#include "Day6.h"


void Day6::run(std::vector<std::string> res_files) {
    std::cout << "Day 6 run" << std::endl;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = getFish(is1);
    std::cout << "Day 6 Part 1: " <<  res.first << std::endl;
    std::cout << "Day 6 Part 2: " <<  res.second << std::endl;
}

std::pair<unsigned long int, unsigned long int> Day6::getFish(std::istream &input) {
    // Read the number of initial fish with given days till reproduction
    unsigned long int part1 = 0;
    std::vector<unsigned long int> fish(9,0);
    std::string read_line; std::getline(input, read_line);
    std::stringstream read_line_ss(read_line);
    for(std::string age; std::getline(read_line_ss, age, ',');) {
        fish[std::stoul(age)]++;
    }
    // Tick through days
    for (unsigned int day = 0; day < 256; day++) {
        unsigned long int new_fish = fish[0];
        for (unsigned int offset = 0; offset < 8; offset++) {
            fish[offset] = fish[offset + 1]; // down tick all fish
        }
        fish[6] += new_fish; // fish that reached day 0 reset to 6
        fish[8] = new_fish; // and each of those fish create a new fish
        if(day == 79) {
            part1 = std::accumulate(fish.begin(), fish.end(), 0UL);
        }
    }
    return {part1, std::accumulate(fish.begin(), fish.end(), 0UL)};

}