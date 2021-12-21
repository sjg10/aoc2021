#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include "Day12.h"
#include "CaveMap.h"


std::vector<std::string> Day12::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getPaths(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}


std::pair<unsigned int, unsigned int> Day12::getPaths(std::istream &input) {
    auto c = CaveMap("start");
    for(std::string read_line; std::getline(input,read_line);) {
        auto split_idx = read_line.find("-");
        auto dest = read_line.substr(split_idx + 1);
        auto src = read_line.substr(0, split_idx);
        c.addEdge(src,dest);
    }
    return c.getPaths("start", "end");
}