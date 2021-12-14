#pragma once
#include "Day.h"

class Day14 : public Day {
    public:
        Day14() {};
        /** Get the created polymer measure score at 10 and 40 steps respectively */
        std::pair<unsigned long int,unsigned long int> getPolymer(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};