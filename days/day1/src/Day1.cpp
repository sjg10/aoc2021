#include <iostream>
#include <fstream>
#include "Day1.h"


void Day1::run(std::vector<std::string> res_files) {
    std::cout << "Day 1 run" << std::endl;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    std::cout << "Day 1 Part 1: " << countIncreases(is1)  << std::endl;
    std::ifstream is2(res_files[0]);
    if(is2.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    std::cout << "Day 1 Part 2: " << countIncreases(is2, 3)  << std::endl;
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