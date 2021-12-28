#pragma once
#include "Day.h"

class Day25 : public Day {
    public:
        Day25(const std::string &input_filename) : Day(input_filename) {};
        /** Get the number of steps to still the herd */
        static unsigned int getSteps(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};