#pragma once
#include "Day.h"

class Day23 : public Day {
    public:
        Day23(const std::string &input_filename) : Day(input_filename) {};
        /** Get shortest amphipod path for both entries */
        static std::pair<unsigned int,unsigned int> findPath(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};