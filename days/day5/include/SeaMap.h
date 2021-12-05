#pragma once
#include <vector>
#include <string>

class SeaMap {
    public:
        SeaMap() {};
        /** Add a plume to the map, optionally ignoring if the plume is a diagonal */
        void addPlume(std::string plume, bool ignore_diagonals = true);
        /** Get how many hotspots have been found so far */
        unsigned int getHotspots() {return m_hotspots;};
    private:
        void resizeMap(unsigned int xmax, unsigned int ymax);
        unsigned int m_hotspots = 0;
        std::vector<std::vector<unsigned int>> m_map = {{}};
};