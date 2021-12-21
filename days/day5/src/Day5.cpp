#include <iostream>
#include <algorithm>
#include "Day5.h"
#include "SeaMap.h"


std::vector<std::string>  Day5::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getHotspots(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
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