#pragma once
#include "Day.h"

class Day11 : public Day {
    public:
        Day11(const std::string &input_filename) : Day(input_filename) {};
        /** Get the number of flashes of the octopuses at turn 100 and the number of turns to synchronise */
        static std::pair<unsigned int,unsigned int> getFlashes(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};