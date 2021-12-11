#pragma once
#include "Day.h"

class Day11 : public Day {
    public:
        Day11() {};
        /** Get the number of flashes of the octopuses at turn 100 and the number of turns to synchronise */
        std::pair<unsigned int,unsigned int> getFlashes(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};