#include <iostream>
#include <fstream>
#include "Day2.h"
#include "Submarine.h"


void Day2::run(std::vector<std::string> res_files) {
    std::cout << "Day 2 run" << std::endl;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto locs = findLocation(is1);
    std::cout << "Day 2 Part 1: " <<  locs.first << std::endl;
    std::cout << "Day 2 Part 2: " <<  locs.second << std::endl;
}


std::pair<int,int> Day2::findLocation(std::istream &instructions) {
    auto s1 = Submarine();
    auto s2 = Submarine();
    for(std::string read_string; std::getline(instructions, read_string);) {
        s1.move_basic(read_string);
        s2.move_aimed(read_string);
    }
    return {s1.getLocation(), s2.getLocation()};
}