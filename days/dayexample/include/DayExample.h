#pragma once
#include "Day.h"

class DayExample : public Day {
    public:
        DayExample(int value);
        void run(std::vector<std::string> res_files) override;
        int getValue();
    private:
        int example_value;
};