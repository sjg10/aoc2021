#include <iostream>
#include "Day17.h"
#include "Probe.h"


std::vector<std::string> Day17::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getProbePath(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned int, unsigned int> Day17::getProbePath(std::istream &input) {
    auto p = Probe(input);
    return p.getPath();
}