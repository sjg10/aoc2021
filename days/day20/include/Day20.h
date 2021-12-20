#pragma once
#include "Day.h"

class Day20 : public Day {
    public:
        Day20() {};
        /** Find the pixel count at 2 and 50 enhancements respectively */
        std::pair<unsigned int,unsigned int> findImage(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};