#pragma once
#include "Day.h"

class Day14 : public Day {
    public:
        Day14(const std::string &input_filename) : Day(input_filename) {};
        /** Get the created polymer measure score at 10 and 40 steps respectively */
        static std::pair<unsigned long int,unsigned long int> getPolymer(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};