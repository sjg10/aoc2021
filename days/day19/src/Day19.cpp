#include <iostream>
#include "Day19.h"
#include "Scanner.h"


std::vector<std::string> Day19::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = findBeacons(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned int, unsigned int> Day19::findBeacons(std::istream &input) {
    std::vector<Scanner> scanners;
    while(input) {
        scanners.push_back(Scanner(input));
    }
    auto beacons = Scanner::getAllBeacons(scanners);   
    return  {beacons.first.size(), Scanner::getMaxManhattanDistance(beacons.second)};
}