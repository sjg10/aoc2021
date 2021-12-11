#include <iostream>
#include <fstream>
#include "Day11.h"
#include "OctoMap.h"


std::vector<std::string> Day11::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = getFlashes(is1);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned int, unsigned int> Day11::getFlashes(std::istream &input) {
    auto o = OctoMap(input);
    unsigned int turn;
    unsigned int part1 = 0;
    for(turn = 1; !o.takeTurn(); turn++) {
        if(turn == 100) {
            part1 = o.getFlashes();
        }
    }
    return {part1, turn};
}