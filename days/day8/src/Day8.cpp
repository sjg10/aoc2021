#include <iostream>
#include <fstream>
#include <algorithm>
#include "Day8.h"
#include "Display.h"


std::vector<std::string> Day8::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = getDigits(is1);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned int, unsigned int> Day8::getDigits(std::istream &input) {
    std::vector<std::set<char>> observed;
    std::vector<std::set<char>> output;
    std::set<char> current;
    unsigned int part1 = 0;
    unsigned int part2 = 0;
    char c;
    bool first_stage = true;
    while (input.get(c) ) {
        if(c == ' ') {
            if(!current.empty()) {
                if(first_stage) {
                    observed.push_back(current);
                }
                else {
                    output.push_back(current);
                }
                current = {};
            }
            
        }
        else if(c == '|') {
            first_stage = false;
        }
        else if (c == '\n'){
            output.push_back(current);
            auto display = Display(observed);
            auto res = display.decodeDigits(output);
            part2 += res;
            while (res > 0) {
                auto mod = res % 10;
                if(mod == 1 || mod == 4 || mod == 7 || mod == 8) { part1++; }
                res /= 10;
            }
            //reset
            current = {};
            first_stage = true;
            output = {};
            observed = {};
        }
        else {
            current.insert(c);
        }
    }
    return  {part1, part2};
}