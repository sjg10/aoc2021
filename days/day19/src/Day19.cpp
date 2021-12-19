#include <iostream>
#include <fstream>
#include "Day19.h"
#include "Scanner.h"


std::vector<std::string> Day19::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = findBeacons(is1);
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