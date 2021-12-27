#include <iostream>
#include <cmath>
#include <map>
#include <list>
#include "Day15.h"
#include "dijkstra.h"


std::vector<std::string> Day15::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getPaths(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

/** Given a map and an integer m multiply the map up by m */
std::vector<int> multiplyMap(const std::vector<int> &map, int m) {
    int s = sqrt(map.size());
    std::vector<int> largemap(s * s * m * m, 0);
    for(int x = 0; x < s; x++) {
    for(int y = 0; y < s; y++) { // for each entry in the old map
        int u = map.at(x + (y * s));
        for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) { // generate the m^2 entries in the new map
            int newval = (((u - 1) + (i + j)) % 9) + 1; // calculate rollover
            int newx = (i * s) + x;
            int newy = (j * s) + y;
            largemap[newx + (newy * m * s)] = newval;
        }
        }
    }
    }
    return largemap;
}

bool win(std::vector<int> const &weights, int* u) {
    int s = sqrt(weights.size());
    return *u == (s * s) - 1;
}

std::map<int, unsigned int> neighbours(std::vector<int> const &weights, int* u) {
    int s = sqrt(weights.size());
    int x = *u % s;
    int y = *u / s;
    std::map<int, unsigned int>  out;
    if (x > 0) { // left
        out[*u - 1] = weights.at(*u - 1);
    }
    if (x < s - 1) { // right
        out[*u + 1] = weights.at(*u + 1);
    }
    if (y > 0) { // up
        out[*u - s] =  weights.at(*u - s);
    }
    if (y < s - 1) { // down            
        out[*u + s] =  weights.at(*u + s);
    }
    return out;
}

              
std::pair<unsigned int, unsigned int> Day15::getPaths(std::istream &input) {
    std::vector<int> map;
    for(std::string read_line; std::getline(input, read_line);) {
        std::transform(read_line.begin(), read_line.end(), std::back_inserter(map),
                    [](unsigned char c){ return c - '0'; });
    }
    unsigned int small = dijkstra<int>(0, 
        std::bind(&win, map, std::placeholders::_1),
        std::bind(&neighbours, map, std::placeholders::_1)
    );
    auto large_map = multiplyMap(map,5);
    unsigned int big = dijkstra<int>(0, 
        std::bind(&win, large_map, std::placeholders::_1),
        std::bind(&neighbours, large_map, std::placeholders::_1)
    );
    return  {small, big};
}