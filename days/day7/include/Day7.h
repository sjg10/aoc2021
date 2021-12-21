#pragma once
#include "Day.h"

class Day7 : public Day {
    public:
        Day7(const std::string &input_filename) : Day(input_filename) {};
        /** Calculate fuel needed according to part 1 and part 2 fuel calculations respectively */
        static std::pair<unsigned long int,unsigned long int> getFuel(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};