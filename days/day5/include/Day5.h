#pragma once
#include "Day.h"

class Day5 : public Day {
    public:
        Day5() {};
        /** Get the plume hotspot counts without and with diagonals respectively */
        std::pair<unsigned int,unsigned int>  getHotspots(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;

};