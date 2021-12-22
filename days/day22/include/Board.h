#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <tuple>

/** Store a cuboidal region in space */
struct Region {
    long int xmin;
    long int xmax;
    long int ymin;
    long int ymax;
    long int zmin;
    long int zmax;

    /** Return the intersection of two regions. THrows out_of_range if do not overlap */
    static Region intersect(const Region &a, const Region &b);
    /** Return if the cuboid is "small" i.e. fits in the intialisation area */
    bool small() const { 
        return xmin >= -50  && xmin <= 50 &&
            xmax >= -50   && xmax <= 50 &&
            ymin >= -50  && ymax <= 50 &&
            ymax >= -50  && ymax <= 50 &&
            zmin >= -50  && zmax <= 50 &&
            zmax >= -50  && zmax <= 50;
    };
    /** Return the size (in components pixels) of the region */
    unsigned long int size() const {
        return ((xmax - xmin) + 1) *
            ((ymax - ymin) + 1) *
            ((zmax - zmin) + 1);
    };
    bool operator<(const Region &r) const {
        return std::make_tuple(xmin,xmax,ymin,ymax,zmin,zmax) < std::make_tuple(r.xmin,r.xmax,r.ymin,r.ymax,r.zmin,r.zmax);
    };
    bool operator==(const Region &r ) const  {
        return std::make_tuple(xmin,xmax,ymin,ymax,zmin,zmax) == std::make_tuple(r.xmin,r.xmax,r.ymin,r.ymax,r.zmin,r.zmax);
    };
    /** Return the non overlapping set of cuboidal regions that cover a with b removed */
    static std::vector<Region> reg_subtract(const Region &a, const Region &b);
};

std::ostream& operator<<(std::ostream &o, const Region &r);

class Board {
    public:
        /** Create an board at its initial state  with the instructions from input */
        Board(std::istream &input);
        /** Get how many are lit after small insturction / all instructions */
        unsigned long int getLit(bool total) const;
    private:
        /** Store pairs of region, on/off */
        std::vector<std::pair<Region,bool>> m_instructions;
};

