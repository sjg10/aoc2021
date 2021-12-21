#include <iostream>
#include <set>
#include <algorithm>
#include "Day13.h"


std::vector<std::string> Day13::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getFolds(input);
    out.push_back(std::to_string(res.first));
    out.push_back(res.second);
    return out;
}

/** Take a dot array and plot it as a string */
std::string plot(const std::set<std::pair<unsigned int, unsigned int>> &dots) {
    unsigned int height = 0;
    unsigned int width = 0;
    for(auto const &dot: dots) {
        if(height < dot.second) { height = dot.second;}
        if(width < dot.first) { width = dot.first;}
    }
    std::string out = "";
    for(unsigned int y = 0; y<= height; y++) {
    for(unsigned int x = 0; x<= width; x++) {
        out.push_back('.');
    }
        out.push_back('\n');
    }
    for(auto const &dot: dots) {
        auto loc = dot.second * (width + 2) + dot.first;
        out[loc] = '#';
    }
    return "\n" + out; // for clearer formatting
}

/** Take a set of dots and transform inplace horizontally/vertically at the given offset */
void fold(std::set<std::pair<unsigned int, unsigned int>> &dots, bool horizontal, unsigned int axis_val) {
    std::set<std::pair<unsigned int, unsigned int>> dots_out;
    std::transform(dots.begin(), dots.end(), std::inserter(dots_out, dots_out.begin()), 
    [horizontal, axis_val](const std::pair<unsigned int, unsigned int> &a) {
        std::pair<unsigned int, unsigned int> out(a.first, a.second);
        if (horizontal && a.second > axis_val) {
            out.second = axis_val - (out.second - axis_val);
        }
        else if (!horizontal && a.first > axis_val) {
            out.first = axis_val - (out.first - axis_val);
        }
        return out;
    }
    );
    dots = dots_out;
}

std::pair<unsigned int, std::string> Day13::getFolds(std::istream &input) {
    std::set<std::pair<unsigned int, unsigned int>> dots;
    bool read_dots = true;
    unsigned int part1 = 0;
    for(std::string read_line; std::getline(input,read_line);) {
        if(read_line.empty()) { // switch between dots to folds
            read_dots = false;
        }
        else if(read_dots) { // Parse new dot
            auto sep = read_line.find(",");
            unsigned int x = std::stoul(read_line.substr(0, sep));
            unsigned int y = std::stoul(read_line.substr(sep + 1));
            dots.insert({x,y});
        }
        else { // parse a fold
            auto sep = read_line.find("=");
            bool horizontal = (read_line[sep - 1] == 'y');
            unsigned int axis_val = std::stoul(read_line.substr(sep + 1));
            fold(dots, horizontal, axis_val);
            if(part1 == 0) {part1 = dots.size();} // get dot count for part 1
        }
    }
    
    return  {part1, plot(dots)};
}