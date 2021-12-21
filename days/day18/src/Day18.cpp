#include <iostream>
#include "Day18.h"
#include "SFNumber.h"


std::vector<std::string> Day18::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = doMaths(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned int, unsigned int> Day18::doMaths(std::istream &input) {
    std::vector<std::string> lines;
    std::string read_line;
    std::getline(input, read_line);
    lines.push_back(read_line);
    auto fullsum = SFNumber(read_line);
    for (;std::getline(input, read_line);)
    {
            lines.push_back(read_line);
            fullsum.radd(SFNumber(read_line));
    }
    unsigned int part2 = 0;
    for(unsigned int i = 0; i < lines.size(); i++) {
    for(unsigned int j = 0; j < lines.size(); j++) {
            auto sum = SFNumber(lines[i]);
            sum.radd(SFNumber(lines[j]));
            auto mag = sum.magnitude();
            if(mag > part2) { part2 = mag;}
    }
    }
    return  {fullsum.magnitude(), part2};
}