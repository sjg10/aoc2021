#pragma once
#include "Day.h"

class Day19 : public Day {
    public:
        Day19(const std::string &input_filename) : Day(input_filename) {};
        /** Find the number of beacons and the largest scanner distance */
        static std::pair<unsigned int,unsigned int> findBeacons(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};