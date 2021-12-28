#pragma once
#include <iostream>
#include <vector>

class CucumberHerds {
    public:
        /** Construct a herd from a stram input */
        CucumberHerds(std::istream &input);
        /** Get the minimum number of seps needed before cucumbers are stationary */
        unsigned int getMinSteps();
        /** Helper function for printing */
        friend std::ostream& operator<<(std::ostream &o, const CucumberHerds &r);
    private:
        bool step();
        enum State {
            EMPTY,
            EAST,
            SOUTH
        };
        std::vector<State> m_state;
        unsigned int m_width;
        unsigned int m_height;
};