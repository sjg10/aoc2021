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

/** Helper class to repredent a beacon */
class Beacon {
    public:
        Beacon(int raw_x, int raw_y, int raw_z) : 
            m_raw_x(raw_x),
            m_raw_y(raw_y),
            m_raw_z(raw_z) {};
        /** Set the rotation */
        void applyRotation(const Rotation &rotation);
        /** Set the translation after the rotation */
        void applyTranslation(const Translation &translation);
        friend class Scanner;
        
    private:
        int m_raw_x;
        int m_raw_y;
        int m_raw_z;

        int m_rot_x;
        int m_rot_y;
        int m_rot_z;

        int m_x;
        int m_y;
        int m_z;
};

/** A launched scanner and its detected beacons */
class Scanner {
    public:
        /** Create a scanner from a stream input */
        Scanner(std::istream &input);
        /** Returns the set of canonical beacons and the ordered array of canonical scanner locations */
        static std::pair<std::set<Point>,std::vector<Point>> getAllBeacons(std::vector<Scanner> scanners);
    private:
        std::pair<std::vector<Point>,Point> getCanonicalBeacons();
        std::vector<int> getPathToZero() const;
        int m_name;
        // how to remap
        std::vector<Scanner *> m_reference;
        std::vector<Rotation> m_rotation;
        std::vector<Translation> m_translation;

        std::set<std::shared_ptr<Beacon>> m_beacons;
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
