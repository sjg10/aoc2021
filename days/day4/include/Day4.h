#pragma once
#include "Day.h"

class Day4 : public Day {
    public:
        Day4() {};
        /** Play bingo and return the first score and the last score */
        std::pair<unsigned int,unsigned int>  playBingo(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};