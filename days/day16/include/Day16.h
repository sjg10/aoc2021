#pragma once
#include "Day.h"

class Day16 : public Day {
    public:
        Day16(const std::string &input_filename) : Day(input_filename) {};
        /** Get the total version and the parsed contents respectively */
        static std::pair<unsigned int,unsigned long int> getMessage(std::istream &input);
        /** Parse the hex string input to a bit array */
        static std::vector<bool> parseInput(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};