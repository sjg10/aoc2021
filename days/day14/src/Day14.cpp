#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "Day14.h"
#include "Polymer.h"


std::vector<std::string> Day14::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getPolymer(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}


std::pair<unsigned long int, unsigned long int> Day14::getPolymer(std::istream &input) {
    std::string read_line; std::getline(input,read_line);
    auto p = Polymer(read_line);
    
    std::getline(input,read_line); // get empty line;
    for(std::string read_line; std::getline(input,read_line);) {
        p.addRule(read_line[0], read_line[1],read_line[6]);
    }
    for(int i = 0; i < 10; i++) {
        p.expand();
    }
    unsigned long int part1 = p.getMeasure();
    for(int i = 0; i < 30; i++) {
        p.expand();
    }
    return {part1, p.getMeasure()};
}