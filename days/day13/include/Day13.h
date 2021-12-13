#pragma once
#include "Day.h"

class Day13 : public Day {
    public:
        Day13() {};
        /** Get the number of dots after one fold and the final plotted dot map respectively */
        std::pair<unsigned int,std::string> getFolds(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};