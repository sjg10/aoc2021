#pragma once
#include "Day.h"

class Day24 : public Day {
    public:
        Day24(const std::string &input_filename) : Day(input_filename) {};
        static std::pair<unsigned long int,unsigned long int> findModel(std::istream &input);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};