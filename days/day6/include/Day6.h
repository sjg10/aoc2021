#pragma once
#include "Day.h"

class Day6 : public Day {
    public:
        Day6(const std::string &input_filename) : Day(input_filename) {};
        /** Get the number of lantern fish after 80 and 256 days respectively */
        static std::pair<unsigned long int,unsigned long int> getFish(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};