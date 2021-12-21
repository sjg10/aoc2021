#pragma once
#include "Day.h"

class Day17 : public Day {
    public:
        Day17(const std::string &input_filename) : Day(input_filename) {};
        /** Get highest y and total paths respectively */
        static std::pair<unsigned int,unsigned int> getProbePath(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};