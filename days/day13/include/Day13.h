#pragma once
#include "Day.h"

class Day13 : public Day {
    public:
        Day13(const std::string &input_filename) : Day(input_filename) {};
        /** Get the number of dots after one fold and the final plotted dot map respectively */
        static std::pair<unsigned int,std::string> getFolds(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};