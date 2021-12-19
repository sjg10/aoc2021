#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <memory>

class Scanner; // forward declare

/** Helper class to represent a rotation */
struct Rotation {
    std::array<int,3> xmap; 
    std::array<int,3> ymap; 
    std::array<int,3> zmap; 
};

// Useful typedefs
using Translation = std::array<int,3>;
using Point = std::array<int,3>;

/** A launched scanner and its detected beacons */
class Scanner {
    public:
        /** Create a scanner from a stream input */
        Scanner(std::istream &input);
        /** Returns the set of canonical beacons and the ordered array of canonical scanner locations */
        static std::pair<std::set<Point>,std::vector<Point>> getAllBeacons(std::vector<Scanner> scanners);
        static unsigned int getMaxManhattanDistance(const std::vector<Point> &points);

    private:
        void findRemappings(std::vector<Scanner> &scanners);
        std::pair<std::vector<Point>,Point> getCanonicalBeacons();
        std::vector<int> getPathToZero() const;
        unsigned int m_name;
        // how to remap
        std::vector<Scanner *> m_reference;
        std::vector<Rotation> m_rotation;
        std::vector<Translation> m_translation;

        std::vector<Point> m_beacons;
        /** The set of 24 rotatio matrices */
        static constexpr std::array<Rotation, 24> ROTATIONS = {
            Rotation{{-1,0,0},{0,-1,0},{0,0,1}},
            Rotation{{-1,0,0},{0,0,-1},{0,-1,0}},
            Rotation{{-1,0,0},{0,0,1},{0,1,0}},
            Rotation{{-1,0,0},{0,1,0},{0,0,-1}},
            Rotation{{0,-1,0},{-1,0,0},{0,0,-1}},
            Rotation{{0,-1,0},{0,0,-1},{1,0,0}},
            Rotation{{0,-1,0},{0,0,1},{-1,0,0}},
            Rotation{{0,-1,0},{1,0,0},{0,0,1}},
            Rotation{{0,0,-1},{-1,0,0},{0,1,0}},
            Rotation{{0,0,-1},{0,-1,0},{-1,0,0}},
            Rotation{{0,0,-1},{0,1,0},{1,0,0}},
            Rotation{{0,0,-1},{1,0,0},{0,-1,0}},
            Rotation{{0,0,1},{-1,0,0},{0,-1,0}},
            Rotation{{0,0,1},{0,-1,0},{1,0,0}},
            Rotation{{0,0,1},{0,1,0},{-1,0,0}},
            Rotation{{0,0,1},{1,0,0},{0,1,0}},
            Rotation{{0,1,0},{-1,0,0},{0,0,1}},
            Rotation{{0,1,0},{0,0,-1},{-1,0,0}},
            Rotation{{0,1,0},{0,0,1},{1,0,0}},
            Rotation{{0,1,0},{1,0,0},{0,0,-1}},
            Rotation{{1,0,0},{0,-1,0},{0,0,-1}},
            Rotation{{1,0,0},{0,0,-1},{0,1,0}},
            Rotation{{1,0,0},{0,0,1},{0,-1,0}},
            Rotation{{1,0,0},{0,1,0},{0,0,1}}
        };
};
