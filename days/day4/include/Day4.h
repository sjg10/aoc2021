#pragma once
#include "Day.h"

class Day4 : public Day {
    public:
        Day4(const std::string &input_filename) : Day(input_filename) {};
        /** Play bingo and return the first score and the last score */
        static std::pair<unsigned int,unsigned int>  playBingo(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};