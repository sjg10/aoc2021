#pragma once
#include "Day.h"

class Day15 : public Day {
    public:
        Day15() {};
        /** Find the shortest path of the small map and the scaled by 5 map respectively */
        std::pair<unsigned int,unsigned int> getPaths(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};