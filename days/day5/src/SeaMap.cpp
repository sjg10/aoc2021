#include <iostream>
#include <sstream>
#include <algorithm>
#include <deque>
#include "SeaMap.h"


void SeaMap::addPlume(std::string plume, bool ignore_diagonals) {
    auto space_idx = plume.find(" -> ");

    std::string start = plume.substr(0, space_idx);
    auto start_sep = start.find(",");
    unsigned int s_x = std::stoul(start.substr(0, start_sep));
    unsigned int s_y = std::stoul(start.substr(start_sep + 1));

    std::string end = plume.substr(space_idx + 4);
    auto end_sep = end.find(",");
    unsigned int e_x = std::stoul(end.substr(0, end_sep));
    unsigned int e_y = std::stoul(end.substr(end_sep + 1));

    auto ys = std::minmax(s_y, e_y);
    auto xs = std::minmax(s_x, e_x);
    if(e_x == s_x) {
        resizeMap(s_x, ys.second);
        for(unsigned int y = ys.first; y <= ys.second; y++) {
            m_map[s_x][y]++;
            if(m_map[s_x][y] == 2) {
                m_hotspots++;
            }
        }
    }
    else if (e_y == s_y) {
        resizeMap(xs.second, s_y);
        for(unsigned int x = xs.first; x <= xs.second; x++) {
            m_map[x][s_y]++;
            if(m_map[x][s_y] == 2) {
                m_hotspots++;
            }
        }
    }
    else if (ys.second - ys.first == xs.second - xs.first) {
        //diagonal type 1
        if(!ignore_diagonals) {
            resizeMap(xs.second, ys.second);
            int x_incr = (s_x < e_x) ? 1 : -1;
            int y_incr = (s_y < e_y) ? 1 : -1;
            for(unsigned int incr = 0; incr <= ys.second - ys.first; incr++) {
                unsigned int x = s_x + (incr * x_incr);
                unsigned int y = s_y + (incr * y_incr);
                m_map[x][y]++;
                if(m_map[x][y] == 2) {
                    m_hotspots++;
                }
            }

        }
    }
    else {
        throw std::runtime_error("Not a straight line: " + plume);
    }
}

/** Resize the map to accomodate (xmax,ymax) */
void SeaMap::resizeMap(unsigned int xmax, unsigned int ymax) {
    if (ymax >= m_map[0].size()) {
        for(auto &row: m_map) {
            row.resize(ymax + 1, 0);
        }
    }
    if(xmax >= m_map.size()) {
        m_map.resize(xmax + 1, std::vector<unsigned int>(m_map[0].size(), 0));
    }
}