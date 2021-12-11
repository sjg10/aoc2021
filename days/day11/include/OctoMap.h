#pragma once
#include <vector>
#include <sstream>


class OctoMap {
    public:
        /** Create an octomap from an input stream grid */
        OctoMap(std::istream &input);
        /** Increment all counters once and perform any flashes and knock ons. Return if all sync'd*/
        bool takeTurn(void);
        /* Get the total flashes seen so far */
        unsigned int getFlashes(void);
    private:
        void checkFlash(unsigned int i, unsigned int j);
        std::vector<std::vector<unsigned int>> m_map;
        unsigned int m_flashes = 0;
        static const unsigned int WIDTH = 10;
        static const unsigned int HEIGHT = 10;
};