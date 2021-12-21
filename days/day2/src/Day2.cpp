#include <iostream>
#include "Day2.h"
#include "Submarine.h"


std::vector<std::string> Day2::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto locs = findLocation(input);
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