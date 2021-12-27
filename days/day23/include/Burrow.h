#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <array>
#include <algorithm>

/** Possible amphipods (or empty non amphipod filled spaces) */
enum Amphipod {
    NONE,
    FORBIDDEN, // this burrow space is not allowed to contain an amphipod, but they can pass through
    A,
    B,
    C,
    D
};

/** A room fof depth N or amphipods to live in */
template <int N>
struct Room {
    std::array<Amphipod,N> cave = {NONE};
    unsigned int fill = 0;
    /** Set the amphipod at the given level (0=bottom, N-1=top) */
    void set(unsigned int level, Amphipod const &amphipod) {
        cave[level] = amphipod;
        fill = std::max(fill, level + 1);
    };
    /** Retrieve the amphipod at the top of the room. out of range error if empty */
    Amphipod top() const {return cave[fill - 1];}
    /** Returns if the room is empty */
    bool isEmpty() const { return fill == 0;}
    /* Removes the amphipod from the top of the room */
    void pop() {if(!isEmpty()) {
        cave[fill - 1] = NONE;
         fill--;}}
    /* Adds an amphipod to the top of the room */
    void push(Amphipod const &a) {
        cave[fill] = a;
         fill++;}
    bool operator<(const Room &r) const {
        return cave < r.cave;
    };
    bool operator==(const Room &r ) const {
        return cave == r.cave;
    };
    /* Returns if the only creatures in the cave are the given amphipod */
    bool onlyContains(Amphipod const &amphipod) const{
        return std::count(cave.begin(), cave.begin() + fill, amphipod) == fill;
    }
    /* Returns if all positions in the cave are filled with the given amphipod */
    bool isAll(Amphipod const &amphipod) const {
        return std::count(cave.begin(), cave.end(), amphipod) == N;
    }
};

/* The state of a burrow with N deep rooms */
template <int N>
struct BurrowState {
    std::array<Amphipod, 11> hall = {NONE,NONE,FORBIDDEN,NONE,FORBIDDEN,NONE,FORBIDDEN,NONE,FORBIDDEN,NONE,NONE};
    Room<N> roomA;
    Room<N> roomB;
    Room<N> roomC;
    Room<N> roomD;
    /** Returns if all rooms contain exactly their residents, and the hall is empty */
    bool isAllHome() const;
    /** get all new valid burrow states from this state, and the energy to get there*/
    std::map<BurrowState<N>, unsigned int> getNeighbours() const;
    bool operator<(const BurrowState<N> &r) const {
        return std::make_tuple(hall,roomA,roomB,roomC,roomD) < std::make_tuple(r.hall,r.roomA,r.roomB,r.roomC,r.roomD);
    };
    bool operator==(const BurrowState<N> &r ) const {
        return std::make_tuple(hall,roomA,roomB,roomC,roomD) == std::make_tuple(r.hall,r.roomA,r.roomB,r.roomC,r.roomD);
    };
};

/** printing helper function for burrow state */
template <int N>
std::ostream& operator<<(std::ostream &o, const BurrowState<N> &r);

class Burrow {
    public:
        Burrow(std::istream& input);
        std::pair<unsigned int,unsigned int> getMinEnergy();
    private:
        BurrowState<2> m_initial_1;
        BurrowState<4> m_initial_2;
};
