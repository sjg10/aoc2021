#pragma once
#include "Day.h"

class Day8 : public Day {
    public:
        Day8() {};
        /** Get the number of 1s,4s,7s and 8s in the displays and the total display sum, respectively */
        std::pair<unsigned int,unsigned int> getDigits(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};