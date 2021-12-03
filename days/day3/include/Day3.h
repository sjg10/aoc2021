#pragma once
#include "Day.h"

class Day3 : public Day {
    public:
        Day3() {};
        void run(std::vector<std::string> res_files) override;
        /** Given submarine status list, find the power consumption */
        unsigned int getPowerConsumption(std::istream &status);
        unsigned int getLifeSupportRating(std::istream &status);

};