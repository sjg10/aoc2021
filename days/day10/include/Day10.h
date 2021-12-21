#pragma once
#include "Day.h"

class Day10 : public Day {
    public:
        Day10(const std::string &input_filename) : Day(input_filename) {};
        /** Get the corrupt score and incomplete score correspondingly */
        static std::pair<unsigned int,unsigned long int> getSyntax(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};