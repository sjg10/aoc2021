#pragma once
#include "Day.h"

class Day21 : public Day {
    public:
        Day21() {};
        /* Find the winning score in a regular and quantum game respecttvely */
        std::pair<unsigned int,unsigned long int> findScore(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};