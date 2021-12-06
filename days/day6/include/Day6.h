#pragma once
#include "Day.h"

class Day6 : public Day {
    public:
        Day6() {};
        void run(std::vector<std::string> res_files) override;
        /** Get the number of lantern fish after 80 and 256 days respectively */
        std::pair<unsigned long int,unsigned long int> getFish(std::istream &input);

};