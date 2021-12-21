#pragma once
#include "Day.h"

class Day2 : public Day {
    public:
        Day2(const std::string &input_filename) : Day(input_filename) {};
        /** Given submarine instruction list, find the location (using basic and aimed interpretations) */
        static std::pair<int,int> findLocation(std::istream &instructions);
    private:
        std::vector<std::string> run(std::ifstream &input) override;

};