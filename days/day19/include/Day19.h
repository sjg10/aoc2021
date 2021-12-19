#pragma once
#include "Day.h"

class Day19 : public Day {
    public:
        Day19() {};
        /** Find the number of beacons and the largest scanner distance */
        std::pair<unsigned int,unsigned int> findBeacons(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};