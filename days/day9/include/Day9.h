#pragma once
#include "Day.h"

class Day9 : public Day {
    public:
        Day9() {};
        std::pair<unsigned int,unsigned int> getDanger(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};