#pragma once
#include "Day.h"

class Day5 : public Day {
    public:
        Day5(const std::string &input_filename) : Day(input_filename) {};
        /** Get the plume hotspot counts without and with diagonals respectively */
        static std::pair<unsigned int,unsigned int>  getHotspots(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;

};