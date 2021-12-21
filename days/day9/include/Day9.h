#pragma once
#include "Day.h"

class Day9 : public Day {
    public:
        Day9(const std::string &input_filename) : Day(input_filename) {};
        static std::pair<unsigned int,unsigned int> getDanger(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};