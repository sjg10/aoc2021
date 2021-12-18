#pragma once
#include "Day.h"

class Day18 : public Day {
    public:
        Day18() {};
        /** Get total sum and largest pairwise sum respecitvely */
        std::pair<unsigned int,unsigned int> doMaths(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};