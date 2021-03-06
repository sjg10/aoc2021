#include <iostream>
#include "Day1.h"


std::vector<std::string> Day1::run(std::ifstream &input) {
    std::vector<std::string> out;
    out.push_back(std::to_string(countIncreases(input)));
    input.clear(); input.seekg(0);
    out.push_back(std::to_string(countIncreases(input, 3)));
    return out;
}

unsigned int Day1::countIncreases(std::istream &depths, unsigned int window_size) {
    unsigned int increases = 0;
    unsigned int line = 0;
    std::vector<unsigned int> running_sums(window_size, 0);
    for(std::string read_string; std::getline(depths, read_string); line++) {
        unsigned int cur_value = std::stoul(read_string);
        /* Only check sums if enough lines are read */
        if(line >= window_size) {
            unsigned int top_window = line % window_size;
            unsigned int next_window = (line + 1) % window_size;
            if (window_size == 1 && running_sums[top_window] < cur_value) {
                increases++; /* If window size is 1 check new value is bigger than old */
            }
            else if(window_size != 1 && running_sums[top_window] < running_sums[next_window] + cur_value) {
                increases++; /* Else check the next window (with the updated sum) is bigger than top window */
            }
            running_sums[top_window] = 0;
        }
        /* Update sums */
        for(unsigned int i = 0; i < std::min(window_size, line + 1); i++) {
            running_sums[i] += cur_value;
        }
    }
    return increases;
}