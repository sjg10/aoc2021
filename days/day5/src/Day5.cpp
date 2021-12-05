#include <iostream>
#include <fstream>
#include <algorithm>
#include "Day5.h"
#include "SeaMap.h"


void Day5::run(std::vector<std::string> res_files) {
    std::cout << "Day 5 run" << std::endl;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = getHotspots(is1);
    std::cout << "Day 5 Part 1: " <<  res.first << std::endl;
    std::cout << "Day 5 Part 2: " <<  res.second << std::endl;
}

std::pair<unsigned int,unsigned int> Day5::getHotspots(std::istream &input) {
    auto s1 = SeaMap();
    auto s2 = SeaMap();
    for (std::string read_line; std::getline(input, read_line);) {
        s1.addPlume(read_line, true);
        s2.addPlume(read_line, false);
    }
    return {s1.getHotspots(), s2.getHotspots()};
}