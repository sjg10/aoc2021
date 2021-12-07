#pragma once
#include "Day.h"

class Day7 : public Day {
    public:
        Day7() {};
        void run(std::vector<std::string> res_files) override;
        /** Calculate fuel needed according to part 1 and part 2 fuel calculations respectively */
        std::pair<unsigned long int,unsigned long int> getFuel(std::istream &input);

};