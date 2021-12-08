#include <iostream>
#include <fstream>
#include "Day7.h"


std::vector<std::string> Day7::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = getFuel(is1);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned long int, unsigned long int> Day7::getFuel(std::istream &input) {
    // Read in and get min/max
    std::vector<unsigned int> positions;
    unsigned int min = std::numeric_limits<unsigned int>::max();
    unsigned int max = std::numeric_limits<unsigned int>::min();
    for (std::string pos; std::getline(input, pos, ',');) {
        unsigned int pos_i = std::stoul(pos);
        if(pos_i < min)  { min = pos_i;}
        if(pos_i > max)  { max = pos_i;}
        positions.push_back(pos_i);
    }

    // Loop through bounds for each posibile end point
    unsigned int part1_total_min = std::numeric_limits<unsigned int>::max();
    unsigned int part2_total_min = std::numeric_limits<unsigned int>::max();
    for (unsigned int x = min; x <= max; x++) {
        unsigned int part1_total = 0;
        unsigned int part2_total = 0;
        // Calculate the fuel needed and check if smallest
        for (auto const &pos: positions) {
            unsigned int distance = std::abs((int)pos - (int)x);
            part1_total += distance;
            part2_total += (distance * (distance + 1)) / 2;
        }
        if(part1_total < part1_total_min) { part1_total_min = part1_total; }
        if(part2_total < part2_total_min) { part2_total_min = part2_total; }
    }
    return  {part1_total_min, part2_total_min};
}