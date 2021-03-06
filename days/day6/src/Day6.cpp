#include <iostream>
#include <sstream>
#include <numeric>
#include "Day6.h"


std::vector<std::string> Day6::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getFish(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
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