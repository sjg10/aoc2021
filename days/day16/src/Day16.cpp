#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include "Day16.h"
#include "Packet.h"


std::vector<std::string> Day16::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = getMessage(is1);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::vector<bool> Day16::parseInput(std::istream &input) {
    std::vector<bool> out; 
    char c;
    while(input.get(c)) {
        unsigned int i = (c >= 'A') ? 10 + (c - 'A') : c - '0';
        for(int idx = 0; idx < 4; idx++) {
            out.push_back(i & 0b1000);
            i <<= 1;
        }
    }
    return out;
}

std::pair<unsigned int, unsigned long int> Day16::getMessage(std::istream &input) {
    auto p = Packet(parseInput(input), 0);
    return  {p.getTotalVersionScore(), p.getContents()};
}