#pragma once
#include "Day.h"

class Day3 : public Day {
    public:
        Day3() {};
        /** Given submarine status list, find the power consumption */
        unsigned int getPowerConsumption(std::istream &status);
        /** Given submarine status list, find the life support rating */
        unsigned int getLifeSupportRating(std::istream &status);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};