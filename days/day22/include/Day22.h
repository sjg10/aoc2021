#pragma once
#include "Day.h"

class Day22 : public Day {
    public:
        Day22(const std::string &input_filename) : Day(input_filename) {};
        /** Get how many are lit after small insturction / all instructions */
        static std::pair<unsigned int,unsigned long int> findLit(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};