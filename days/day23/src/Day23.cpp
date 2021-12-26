#include <iostream>
#include <map>
#include "Day23.h"
#include "Burrow.h"


std::vector<std::string> Day23::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = findPath(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}



std::pair<unsigned int, unsigned int> Day23::findPath(std::istream &input) {
    auto b = Burrow(input);
    return b.getMinEnergy();
}
