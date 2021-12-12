#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include "Day12.h"


std::vector<std::string> Day12::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = getPaths(is1);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

/** Count the paths from start to end using the vertices in map.
 *  Recursively use visited to prevent double visits of small caves
 * Except for one small double if double_visit is false
 * Returns (total paths with no double visits, total paths with a single double visit)
 */
std::pair<unsigned int, unsigned int> paths(std::string start, std::string end, std::map<std::string, std::set<std::string>> map, std::set<std::string> visited = {}, bool doubled_path = false) {
    std::set<std::string> new_visited = visited;
    new_visited.insert(start);
    unsigned int out_doubled = 0;
    unsigned int out_undoubled = 0;
    for(auto const &dest : map[start]) {
        if (dest == end) {
            if (doubled_path) out_doubled++;
            else out_undoubled++;
        }
        else if (std::all_of(dest.begin(), dest.end(), [](unsigned char c) {return std::isupper(c);})) {
            // large cave
            auto res = paths(dest, "end", map, new_visited, doubled_path);
            out_undoubled += res.first;
            out_doubled += res.second;
        }
        else if (!visited.count(dest)) {
            // unvisited small cave
            auto res = paths(dest, "end", map, new_visited, doubled_path);
            out_undoubled += res.first;
            out_doubled += res.second;
        }
        else if (!doubled_path && dest != "start" && dest != "end") {
            // once visited double visit small cave
            auto res = paths(dest, "end", map, new_visited, true);
            out_undoubled += res.first;
            out_doubled += res.second;
        }
    }
    return {out_undoubled, out_doubled};
}

std::pair<unsigned int, unsigned int> Day12::getPaths(std::istream &input) {
    std::map<std::string, std::set<std::string>> map;
    for(std::string read_line; std::getline(input,read_line);) {
        auto split_idx = read_line.find("-");
        auto dest = read_line.substr(split_idx + 1);
        auto src = read_line.substr(0, split_idx);
        if(!map.count(src)) {map[src] = {};}
        if(!map.count(dest)) {map[dest] = {};}
        map[src].insert(dest);
        map[dest].insert(src);
    }
    auto res = paths("start", "end", map);
    return {res.first, res.first + res.second};
}