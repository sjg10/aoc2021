#include "Board.h"
#include <sstream>
Board::Board(std::istream &input) {
    for(std::string read_line; std::getline(input, read_line);) {
        bool on = read_line.substr(0,3) == "on ";
        char onoff[10];
        long int xmin, xmax, ymin, ymax, zmin, zmax;
        sscanf(read_line.c_str(), "%s x=%li..%li,y=%li..%li,z=%li..%li",
             onoff, &xmin, &xmax, &ymin, &ymax, &zmin, &zmax);
        (void) onoff;
        m_instructions.push_back({Region{.xmin=xmin,.xmax=xmax,.ymin=ymin,.ymax=ymax,.zmin=zmin,.zmax=zmax}, on});
    }
}


/**
 * Given a set of non overlapping regions (old) and a new single region (newreg),
 * return a set of non overlapping regions covering the same area as
 * the old regions, removing the newreg from them
 */
std::vector<Region> region_difference(std::vector<Region> old, const Region &newreg) {
    std::vector<Region> out = {};
    for(auto const & r_old: old) {
            auto tmp = Region::reg_subtract(r_old, newreg);
            out.insert(out.end(), tmp.begin(), tmp.end());
    }
    return out;
}


/**
 * Given a set of non overlapping regions (old) and a new single region (newreg),
 * return a set of non overlapping regions covering the same area as
 * the old regions, and the newreg in addition
 */
std::vector<Region> region_union(std::vector<Region> old, const Region &newreg) {
    std::vector<Region> out = region_difference(old, newreg);
    out.push_back(newreg);
    return out;
}

unsigned long int Board::getLit(bool total) const {
    std::vector<Region> lit = {}; // non self intersecting set of lit regions
    for (auto const &[r,on]: m_instructions) {
        if(!total && !r.small()) {continue;} // skip big areas for starters
        if (on) {lit = region_union(lit, r);}
        else    {lit = region_difference(lit, r);}
    }
    unsigned long int out = 0;
    for (auto const &r: lit) {
        out += r.size();
    }
    return out;
}


std::ostream& operator<<(std::ostream &o, const Region &r) {
    o << "([" <<r.xmin << "," << r.xmax <<  "],";
    o << "[" <<r.ymin << "," << r.ymax <<  "],";
    o << "[" <<r.zmin << "," << r.zmax <<  "])";
    return o;
}

std::vector<Region> Region::reg_subtract(const Region &a, const Region &b) {
    Region c;
    try {
        c = intersect(a,b);
    }
    catch(std::out_of_range &e) {return {a};} // non overlapping

    //Now c is fully contained in a
    std::vector<Region> out;
    //top
    if (c.xmax + 1 <= a.xmax) {
        out.push_back(Region{
            c.xmax + 1, a.xmax,
            a.ymin, a.ymax,
            a.zmin, a.zmax});
    }
    //bottom
    if (a.xmin <= c.xmin - 1) {
        out.push_back(Region{
            a.xmin, c.xmin - 1,
            a.ymin, a.ymax,
            a.zmin, a.zmax});
    }
    //front
    if (a.zmin <= c.zmin - 1) {
        out.push_back(Region{
            c.xmin, c.xmax,
            a.ymin, a.ymax,
            a.zmin, c.zmin - 1});
    }
    //back
    if (c.zmax + 1 <=  a.zmax) {
        out.push_back(Region{
            c.xmin, c.xmax,
            a.ymin, a.ymax,
            c.zmax + 1, a.zmax});
    }
    //left side
    if (a.ymin <=  c.ymin - 1) {
    out.push_back(Region{
        c.xmin, c.xmax,
        a.ymin, c.ymin - 1,
        c.zmin, c.zmax});
    }
    //right side
    if (c.ymax + 1 <= a.ymax) {
        out.push_back(Region{c.xmin, c.xmax,
            c.ymax + 1, a.ymax,
            c.zmin, c.zmax});
    }
    return out;
}

Region Region::intersect(const Region &a, const Region &b) {
    if(b.xmin > a.xmax || b.xmax < a.xmin) {
        throw std::out_of_range("no intersect"); // no overlap!
    }
    else if(b.ymin > a.ymax || b.ymax < a.ymin) {
        throw std::out_of_range("no intersect"); // no overlap!
    }
    else if(b.zmin > a.zmax || b.zmax < a.zmin) {
        throw std::out_of_range("no intersect"); // no overlap!
    }
    else {
        return Region{
            std::max(a.xmin, b.xmin),
            std::min(a.xmax, b.xmax),
            std::max(a.ymin, b.ymin),
            std::min(a.ymax, b.ymax),
            std::max(a.zmin, b.zmin),
            std::min(a.zmax, b.zmax)
        };
    }
}