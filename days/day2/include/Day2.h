#pragma once
#include "Day.h"

class Day2 : public Day {
    public:
        Day2() {};
        void run(std::vector<std::string> res_files) override;
        /** Given submarine instruction list, find the location (using basic and aimed interpretations) */
        std::pair<int,int> findLocation(std::istream &instructions);

};