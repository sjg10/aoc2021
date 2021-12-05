#pragma once
#include "Day.h"

class Day5 : public Day {
    public:
        Day5() {};
        void run(std::vector<std::string> res_files) override;
        /** Get the plume hotspot counts without and with diagonals respectively */
        std::pair<unsigned int,unsigned int>  getHotspots(std::istream &input);

};