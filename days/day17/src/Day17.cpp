#include <iostream>
#include <fstream>
#include <cmath>
#include "Day17.h"


std::vector<std::string> Day17::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = getProbePath(is1);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

// Check if ux,  uy initial velocity hits box
bool Day17::getCollision(int ux, int uy) {
    int vx = ux;
    int vy = uy;
    int x = 0;
    int y = 0;
    while (true) {
        if (vx == 0 && x < m_bounds.xmin) {
            return false;
        }
        if (x > m_bounds.xmax) {
            return false;
        }
        if (vy < 0 && y < m_bounds.ymin) {
            return false;
        }
        if( x >= m_bounds.xmin && x <= m_bounds.xmax && y >= m_bounds.ymin && y <= m_bounds.ymax) {
            return true;
        }
        x+=vx;
        y+=vy;
        vy--;
        if(vx > 0) {vx--;}
        else if(vx < 0) {vx++;}
    }
}

// CFind solution after parseInput
std::pair<unsigned int, unsigned long int> Day17::getProbePathParsed() {
    // Some large bounds, outside of which we will never hit the target
    int ux_max = m_bounds.xmax;
    int ux_min = 1;
    int uy_max = ux_max;
    int uy_min = m_bounds.ymin;

    bool collided = false;
    int part1 = 0;
    int part2 = 0;
    // Test evrey possible speed
    // Start with the largest ux sow e can get the highest y first
    for(int uy = uy_max; uy >= uy_min; uy--) { 
        for(int ux = ux_max; ux >= ux_min; ux--) {
            if(getCollision(ux, uy)) { 
                if(!collided) { //If first collision
                    int tmp_uy = uy; // get max y
                    while(tmp_uy > 0) {
                        part1 += tmp_uy--;
                    }
                    collided = true;
                }
                part2++; // count the collision
            }
        }
    }
    return {part1,part2};
}

// Create the m_bounds from an input
void Day17::parseInput(std::istream &input) {
    std::string read_line;
    std::getline(input, read_line);
    auto x_pos = read_line.find("x=");
    auto x_pos_dot = read_line.find("..", x_pos);
    auto comma_pos = read_line.find(",");
    auto y_pos = read_line.find("y=");
    auto y_pos_dot = read_line.find("..", y_pos);
    int xmin = std::stoi(read_line.substr(x_pos + 2, x_pos_dot - (x_pos + 2)));
    int xmax = std::stoi(read_line.substr(x_pos_dot + 2, comma_pos - (x_pos_dot + 2)));
    int ymin = std::stoi(read_line.substr(y_pos + 2, y_pos_dot - (y_pos + 2)));
    int ymax = std::stoi(read_line.substr(y_pos_dot + 2));
    
    m_bounds =  Bounds{
        .xmin = xmin,
        .xmax = xmax,
        .ymin = ymin,
        .ymax = ymax
    };

}
std::pair<unsigned int, unsigned int> Day17::getProbePath(std::istream &input) {
    parseInput(input);
    return getProbePathParsed();
}