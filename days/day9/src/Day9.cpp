#include <iostream>
#include <algorithm>
#include <set>
#include "Day9.h"


std::vector<std::string> Day9::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getDanger(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

/** Given a partially built 10-padded map return the coords of low points on its penultimate row */
std::vector<std::pair<unsigned int, unsigned int>> getLowRisks(const std::vector<std::vector<unsigned int>> &heights) {
    std::vector<std::pair<unsigned int, unsigned int>> coords = {};
    unsigned int l = heights.size();
    unsigned int out = 0;
    if (heights.size() >= 2) {
        for (unsigned int i= 1; i < heights[l - 2].size() - 1; i++) {
            unsigned int loc = heights[l-2][i];
            if (loc < heights[l-2][i - 1] &&
                loc < heights[l-2][i + 1] &&
                loc < heights[l-3][i] &&
                loc < heights[l-1][i]) {
                    coords.push_back({l - 2, i});
                    out += loc + 1;
                }
        }
    }
    return coords;
}

/** Given a 10-padded map and a low point on that map, return the size of that low point's basin */
unsigned int findBasin(const std::vector<std::vector<unsigned int>> &heights, const std::pair<unsigned int, unsigned int> &l) {
    std::set<std::pair<unsigned int, unsigned int>> basin = {l};
    std::set<std::pair<unsigned int, unsigned int>> cur_search = {l};
    std::set<std::pair<unsigned int, unsigned int>> next_search = {};
    while(!cur_search.empty()) {
        for(auto const &x : cur_search) {
            if(heights[x.first][x.second + 1] < 9) {next_search.insert({x.first,x.second + 1});}
            if(heights[x.first][x.second - 1] < 9) {next_search.insert({x.first,x.second - 1});}
            if(heights[x.first + 1][x.second] < 9) {next_search.insert({x.first + 1,x.second});}
            if(heights[x.first - 1][x.second] < 9) {next_search.insert({x.first - 1,x.second});}
        }
        cur_search = {};
        std::set_difference(next_search.begin(), next_search.end(), basin.begin(), basin.end(),
            std::inserter(cur_search, cur_search.end()));
        basin.insert(next_search.begin(), next_search.end());
    }
    return basin.size();

}

std::pair<unsigned int, unsigned int> Day9::getDanger(std::istream &input) {
    // Map - padded with 10's along the border to remove indexing issues.
    std::vector<std::vector<unsigned int>> heights = {{10}};
    char c;
    std::vector<std::pair<unsigned int, unsigned int>> low_points = {};
    while(input.get(c)) {
        if (c == '\n') {
            heights.back().push_back(10); // right padding
            if(heights.size() == 1) { // top padding
                heights.emplace(heights.begin(), std::vector<unsigned int>(heights[0].size(),10));
            }
            auto new_lows = getLowRisks(heights);
            low_points.insert(low_points.end(), new_lows.begin(), new_lows.end());
            heights.push_back({10}); // left padding
        }
        else {
            heights.back().push_back(c - '0');
        }
    }
    // Compute final line
    heights.back() = std::vector<unsigned int>(heights[0].size(),10); // bottom padding
    auto new_lows = getLowRisks(heights);
    low_points.insert(low_points.end(), new_lows.begin(), new_lows.end());

    //Calculate part 1 and find basins
    unsigned int part1 = 0;
    std::vector<unsigned int> basin_sizes;
    for(auto const &l: low_points) {
        part1 += heights[l.first][l.second] + 1;
        basin_sizes.push_back(findBasin(heights, l));
    }

    // Partially sort descending basin_sizes to get three largest
    std::nth_element(basin_sizes.begin(), basin_sizes.begin()+2, basin_sizes.end(), std::greater{});
    
    return  {part1, basin_sizes[0] * basin_sizes[1] * basin_sizes[2]};
}