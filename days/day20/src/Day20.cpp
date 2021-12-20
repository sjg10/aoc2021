#include <iostream>
#include <fstream>
#include "Day20.h"
#include "Image.h"


std::vector<std::string> Day20::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = findImage(is1);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned int, unsigned int> Day20::findImage(std::istream &input) {
    auto img = Image(input);
    for(int i = 0; i < 2 ; i++) {
        img.enhance();
    }
    unsigned int part1 = img.pixelCount();
    for (int i = 2; i < 50; i++) {
        img.enhance();
    }
    return {part1, img.pixelCount()};
}
