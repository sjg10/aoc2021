#pragma once
#include "Day.h"

class Day4 : public Day {
    public:
        Day4() {};
        void run(std::vector<std::string> res_files) override;
        /** Play bingo and return the first score and the last score */
        std::pair<unsigned int,unsigned int>  playBingo(std::istream &input);

};