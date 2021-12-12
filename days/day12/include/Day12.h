#pragma once
#include "Day.h"

class Day12 : public Day {
    public:
        Day12() {};
        /** Get the count of paths through the caves with no, and no more than one, double visit, respectively */
        std::pair<unsigned int,unsigned int> getPaths(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};