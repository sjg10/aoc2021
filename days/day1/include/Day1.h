#pragma once
#include "Day.h"

class Day1 : public Day {
    public:
        Day1() {};
        void run(std::vector<std::string> res_files) override;
        /** Count the increasing steps in a stream of depth values. 
         * Aggregate the sums over given window size
         */
        unsigned int countIncreases(std::istream &depths, unsigned int window_size = 1);
    private:
        int example_value;
};