#pragma once
#include "Day.h"

class Day20 : public Day {
    public:
        Day20(const std::string &input_filename) : Day(input_filename) {};
        /** Find the pixel count at 2 and 50 enhancements respectively */
        static std::pair<unsigned int,unsigned int> findImage(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};