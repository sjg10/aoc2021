#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <array>
#include <algorithm>

enum Amphipod {
    NONE,
    FORBIDDEN, // this burrow space is not allowed to contain an amphipod, but they can pass through
    A,
    B,
    C,
    D
};

template <int N>
struct Room {
    std::array<Amphipod,N> cave = {NONE};
    unsigned int fill = 0;
    void set(unsigned int level, Amphipod const &amphipod) {
        cave[level] = amphipod;
        fill = std::max(fill, level + 1);
    };
    Amphipod top() const {return cave[fill - 1];}
    bool isEmpty() const { return fill == 0;}
    void pop() {if(!isEmpty()) {
        cave[fill - 1] = NONE;
         fill--;}}
    void push(Amphipod const &a) {
        cave[fill] = a;
         fill++;}
    bool operator<(const Room &r) const {
        return cave < r.cave;
    };
    bool operator==(const Room &r ) const {
        return cave == r.cave;
    };
    bool onlyContains(Amphipod const &amphipod) const{
        return std::count(cave.begin(), cave.begin() + fill, amphipod) == fill;
    }
    bool isAll(Amphipod const &amphipod) const {
        return std::count(cave.begin(), cave.end(), amphipod) == N;
    }
};


template <int N>
struct BurrowState {
    std::array<Amphipod, 11> hall = {NONE,NONE,FORBIDDEN,NONE,FORBIDDEN,NONE,FORBIDDEN,NONE,FORBIDDEN,NONE,NONE};
    Room<N> roomA;
    Room<N> roomB;
    Room<N> roomC;
    Room<N> roomD;
    bool isAllHome() const;
    std::map<BurrowState<N>, unsigned int> getNeighbours() const; // get all new valid burrow states from this state, and the energy to get there
    bool operator<(const BurrowState<N> &r) const {
        return std::make_tuple(hall,roomA,roomB,roomC,roomD) < std::make_tuple(r.hall,r.roomA,r.roomB,r.roomC,r.roomD);
    };
    bool operator==(const BurrowState<N> &r ) const {
        return std::make_tuple(hall,roomA,roomB,roomC,roomD) == std::make_tuple(r.hall,r.roomA,r.roomB,r.roomC,r.roomD);
    };
};

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
