#pragma once
#include <sstream>
#include <string>

class Probe {
    public:
        Probe(std::istream &input);
        /** Get highest y and total paths respectively */
        std::pair<unsigned int, unsigned long int> getPath();
    private:
        struct Bounds {
            int xmin;
            int xmax;
            int ymin;
            int ymax;
        };
        bool getCollision(int ux, int uy);
        Bounds m_bounds;
};