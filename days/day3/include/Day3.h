#pragma once
#include "Day.h"

class Day3 : public Day {
    public:        
        Day3(const std::string &input_filename) : Day(input_filename) {};
        /** Given submarine status list, find the power consumption */
        static unsigned int getPowerConsumption(std::istream &status);
        /** Given submarine status list, find the life support rating */
        static unsigned int getLifeSupportRating(std::istream &status);
    private:
        std::vector<std::string> run(std::ifstream &input) override;
};