#pragma once
#include "Day.h"

class Day15 : public Day {
    public:
        Day15(const std::string &input_filename) : Day(input_filename) {};
        /** Find the shortest path of the small map and the scaled by 5 map respectively */
        static std::pair<unsigned int,unsigned int> getPaths(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};