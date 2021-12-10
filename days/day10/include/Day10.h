#pragma once
#include "Day.h"

class Day10 : public Day {
    public:
        Day10() {};
        /** Get the corrupt score and incomplete score correspondingly */
        std::pair<unsigned int,unsigned long int> getSyntax(std::istream &input);
    private:
        std::vector<std::string> run(std::vector<std::string> res_files) override;
};