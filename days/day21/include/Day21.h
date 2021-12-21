#pragma once
#include "Day.h"

class Day21 : public Day {
    public:
        Day21(const std::string &input_filename) : Day(input_filename) {};
        /* Find the winning score in a regular and quantum game respecttvely */
        static std::pair<unsigned int,unsigned long int> findScore(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};