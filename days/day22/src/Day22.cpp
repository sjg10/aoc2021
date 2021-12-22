#include <iostream>
#include <map>
#include "Day22.h"
#include "Board.h"


std::vector<std::string> Day22::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = findLit(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}



std::pair<unsigned int, unsigned long int> Day22::findLit(std::istream &input) {
    auto b = Board(input);
    return {b.getLit(false), b.getLit(true)};
}
