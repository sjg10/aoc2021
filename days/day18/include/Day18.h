#pragma once
#include "Day.h"

class Day18 : public Day {
    public:
        Day18(const std::string &input_filename) : Day(input_filename) {};
        /** Get total sum and largest pairwise sum respecitvely */
        static std::pair<unsigned int,unsigned int> doMaths(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};