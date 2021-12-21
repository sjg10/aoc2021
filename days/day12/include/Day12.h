#pragma once
#include "Day.h"

class Day12 : public Day {
    public:
        Day12(const std::string &input_filename) : Day(input_filename) {};
        /** Get the count of paths through the caves with no, and no more than one, double visit, respectively */
        static std::pair<unsigned int,unsigned int> getPaths(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};