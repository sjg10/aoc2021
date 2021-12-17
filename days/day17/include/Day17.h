#pragma once
#include "Day.h"

class Day17 : public Day {
    public:
        Day17() {};
        /** Get highest y and totalk paths respectively */
        std::pair<unsigned int,unsigned int> getProbePath(std::istream &input);
    private:
        struct Bounds {
            int xmin;
            int xmax;
            int ymin;
            int ymax;
        };
        std::vector<std::string> run(std::vector<std::string> res_files) override;
        std::pair<unsigned int, unsigned long int> getProbePathParsed();
        void parseInput(std::istream &input);
        bool getCollision(int ux, int uy);
        Bounds m_bounds;
};