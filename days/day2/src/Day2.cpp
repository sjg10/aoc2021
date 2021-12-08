#include <iostream>
#include <fstream>
#include "Day2.h"
#include "Submarine.h"


std::vector<std::string> Day2::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto locs = findLocation(is1);
    out.push_back(std::to_string(locs.first));
    out.push_back(std::to_string(locs.second));
    return out;
}


std::pair<int,int> Day2::findLocation(std::istream &instructions) {
    auto s1 = Submarine();
    auto s2 = Submarine();
    for(std::string read_string; std::getline(instructions, read_string);) {
        s1.moveBasic(read_string);
        s2.moveAimed(read_string);
    }
    return {s1.getLocation(), s2.getLocation()};
}