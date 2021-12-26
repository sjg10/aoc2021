#include "Burrow.h"
#include <queue>

template <int N>
bool BurrowState<N>::isAllHome() const {
    return roomA.isAll(A) &&
        roomB.isAll(B) &&
        roomC.isAll(C) &&
        roomD.isAll(D);
}

Amphipod getAmphipod(char c) {
    switch(c) {
        case 'A': return A;
        case 'B': return B;
        case 'C': return C;
        case 'D': return D;
        default: return NONE;
    }
}

char getAmphipodChar(Amphipod const &a) {
    switch(a) {
        case A: return 'A';
        case B: return 'B';
        case C: return 'C';
        case D: return 'D';
        case NONE:
        case FORBIDDEN:// fallthrough
            return '.'; 
        default: return '#';
    }
}

int getAmphipodEnergy(Amphipod const &a) {
    switch(a) {
        case A: return 1;
        case B: return 10;
        case C: return 100;
        case D: return 1000;
        default: return 0;
    }
}

int getRoomEntrance(Amphipod const &a) {
    switch(a) {
        case A: return 2;
        case B: return 4;
        case C: return 6;
        case D: return 8;
        default: return 0;
    }
}

Burrow::Burrow(std::istream &input) {
    std::string read_line;
    std::getline(input, read_line); //ignore
    std::getline(input, read_line); // ignore
    std::getline(input, read_line);
    m_initial_1.roomA.set(1,getAmphipod(read_line[3]));
    m_initial_2.roomA.set(3,getAmphipod(read_line[3]));
    m_initial_1.roomB.set(1,getAmphipod(read_line[5]));
    m_initial_2.roomB.set(3,getAmphipod(read_line[5]));
    m_initial_1.roomC.set(1,getAmphipod(read_line[7]));
    m_initial_2.roomC.set(3,getAmphipod(read_line[7]));
    m_initial_1.roomD.set(1,getAmphipod(read_line[9]));
    m_initial_2.roomD.set(3,getAmphipod(read_line[9]));

    m_initial_2.roomA.set(2,D);
    m_initial_2.roomA.set(1,D);
    m_initial_2.roomB.set(2,C);
    m_initial_2.roomB.set(1,B);
    m_initial_2.roomC.set(2,B);
    m_initial_2.roomC.set(1,A);
    m_initial_2.roomD.set(2,A);
    m_initial_2.roomD.set(1,C);

    std::getline(input, read_line);
    m_initial_1.roomA.set(0,getAmphipod(read_line[3]));
    m_initial_2.roomA.set(0,getAmphipod(read_line[3]));
    m_initial_1.roomB.set(0,getAmphipod(read_line[5]));
    m_initial_2.roomB.set(0,getAmphipod(read_line[5]));
    m_initial_1.roomC.set(0,getAmphipod(read_line[7]));
    m_initial_2.roomC.set(0,getAmphipod(read_line[7]));
    m_initial_1.roomD.set(0,getAmphipod(read_line[9]));
    m_initial_2.roomD.set(0,getAmphipod(read_line[9]));
}

template <int N>
std::ostream& operator<<(std::ostream &o, const BurrowState<N> &r) {
    std::string out = "#############\n"
                      "#...........#\n"
                      "###.#.#.#.###\n";
    for ( int i = 0; i < N - 1; i ++) {
        out +=        "  #.#.#.#.#  \n";
    }
    out +=            "  #########";
    for(unsigned int i = 0; i < r.hall.size(); i++) {
        out[14 + 1 + i] = getAmphipodChar(r.hall.at(i));
    }
    for(int i = 0; i < N; i++) {
            out[(14 * (2 + N - (i + 1))) + 3] = getAmphipodChar(r.roomA.cave[i]);
            out[(14 * (2 + N - (i + 1))) + 5] = getAmphipodChar(r.roomB.cave[i]);
            out[(14 * (2 + N - (i + 1))) + 7] = getAmphipodChar(r.roomC.cave[i]);
            out[(14 * (2 + N - (i + 1))) + 9] = getAmphipodChar(r.roomD.cave[i]);
    }
    o << out;
    return o;
}

template <int N>
std::map<BurrowState<N>, unsigned int> BurrowState<N>::getNeighbours() const {
    std::map<BurrowState<N>, unsigned int> out;
    //room move
    if(!roomA.isEmpty() && !roomA.onlyContains(A) ) {
        for(int i = getRoomEntrance(A); i >= 0; i--) { // move into left hall
            if(hall[i] == FORBIDDEN) { 
                continue;
            }
            else if (hall[i] == NONE) {
                auto newhall = hall;
                auto newA = roomA;
                newhall[i] = roomA.top();
                newA.pop();
                out[BurrowState<N>{newhall, newA, roomB, roomC, roomD}] = 
                    ((N - roomA.fill) + 1 + (getRoomEntrance(A) - i)) * getAmphipodEnergy(roomA.top());
            }
            else { // hall blocked
                break;
            }
        }
        for(unsigned int i = getRoomEntrance(A); i < hall.size(); i++) { // move into right hall
            if(hall[i] == FORBIDDEN) { 
                continue;
            }
            else if (hall[i] == NONE) {
                auto newhall = hall;
                auto newA = roomA;
                newhall[i] = roomA.top();
                newA.pop();
                out[BurrowState<N>{newhall, newA, roomB, roomC, roomD}] = 
                    ((N - roomA.fill) + 1 + (i - getRoomEntrance(A))) * getAmphipodEnergy(roomA.top());
            }
            else { // hall blocked
                break;
            }
        }
    }
    if(!roomB.isEmpty() && !roomB.onlyContains(B) ) {
        for(int i = getRoomEntrance(B); i >= 0; i--) { // move into left hall
            if(hall[i] == FORBIDDEN) { 
                continue;
            }
            else if (hall[i] == NONE) {
                auto newhall = hall;
                auto newB = roomB;
                newhall[i] = roomB.top();
                newB.pop();
                out[BurrowState<N>{newhall, roomA, newB, roomC, roomD}] = 
                    ((N - roomB.fill) + 1 + (getRoomEntrance(B) - i)) * getAmphipodEnergy(roomB.top());
            }
            else { // hall blocked
                break;
            }
        }
        for(unsigned int i = getRoomEntrance(B); i < hall.size(); i++) { // move into right hall
            if(hall[i] == FORBIDDEN) { 
                continue;
            }
            else if (hall[i] == NONE) {
                auto newhall = hall;
                auto newB = roomB;
                newhall[i] = roomB.top();
                newB.pop();
                out[BurrowState<N>{newhall, roomA, newB, roomC, roomD}] = 
                    ((N - roomB.fill) + 1 + (i - getRoomEntrance(B))) * getAmphipodEnergy(roomB.top());
            }
            else { // hall blocked
                break;
            }
        }
    }
    if(!roomC.isEmpty() && !roomC.onlyContains(C) ) {
        for(int i = getRoomEntrance(C); i >= 0; i--) { // move into left hall
            if(hall[i] == FORBIDDEN) { 
                continue;
            }
            else if (hall[i] == NONE) {
                auto newhall = hall;
                auto newC = roomC;
                newhall[i] = roomC.top();
                newC.pop();
                out[BurrowState<N>{newhall, roomA, roomB, newC, roomD}] = 
                    ((N - roomC.fill) + 1 + (getRoomEntrance(C) - i)) * getAmphipodEnergy(roomC.top());
            }
            else { // hall blocked
                break;
            }
        }
        for(unsigned int i = getRoomEntrance(C); i < hall.size(); i++) { // move into right hall
            if(hall[i] == FORBIDDEN) { 
                continue;
            }
            else if (hall[i] == NONE) {
                auto newhall = hall;
                auto newC = roomC;
                newhall[i] = roomC.top();
                newC.pop();
                out[BurrowState<N>{newhall, roomA, roomB, newC, roomD}] = 
                    ((N - roomC.fill) + 1 + (i - getRoomEntrance(C))) * getAmphipodEnergy(roomC.top());
            }
            else { // hall blocked
                break;
            }
        }
    }
    if(!roomD.isEmpty() && !roomD.onlyContains(D) ) {
        for(int i = getRoomEntrance(D); i >= 0; i--) { // move into left hall
            if(hall[i] == FORBIDDEN) { 
                continue;
            }
            else if (hall[i] == NONE) {
                auto newhall = hall;
                auto newD = roomD;
                newhall[i] = roomD.top();
                newD.pop();
                out[BurrowState<N>{newhall, roomA, roomB, roomC, newD}] = 
                    ((N - roomD.fill) + 1 + (getRoomEntrance(D) - i)) * getAmphipodEnergy(roomD.top());
            }
            else { // hall blocked
                break;
            }
        }
        for(unsigned int i = getRoomEntrance(D); i < hall.size(); i++) { // move into right hall
            if(hall[i] == FORBIDDEN) { 
                continue;
            }
            else if (hall[i] == NONE) {
                auto newhall = hall;
                auto newD = roomD;
                newhall[i] = roomD.top();
                newD.pop();
                out[BurrowState<N>{newhall, roomA, roomB, roomC, newD}] = 
                    ((N - roomD.fill) + 1 + (i - getRoomEntrance(D))) * getAmphipodEnergy(roomD.top());
            }
            else { // hall blocked
                break;
            }
        }
    }
    // from hall into room
    for(int i = 0; i < (int)hall.size(); i++) {
        switch(hall[i]) {
            case A:
                if(roomA.onlyContains(A)) {
                    if(i < getRoomEntrance(A)) {
                        bool freepath = true;
                        for(int j = i + 1; j <= getRoomEntrance(A); j++) {
                            if(hall[j] != NONE && hall[j] != FORBIDDEN) {
                                freepath = false;
                                break;
                            }
                        }
                        if(freepath) {
                            auto newhall = hall;
                            auto newA = roomA;
                            newhall[i] = NONE;
                            newA.push(A);
                            out[BurrowState<N>{newhall,newA, roomB, roomC, roomD}] = 
                                ((getRoomEntrance(A) - i) + N - roomA.fill) * getAmphipodEnergy(A);
                        }
                    }
                    else {
                        bool freepath = true;
                        for(int j = i - 1; j >= getRoomEntrance(A); j--) {
                            if(hall[j] != NONE && hall[j] != FORBIDDEN) {
                                freepath = false;
                                break;
                            }
                        }
                        if(freepath) {
                            auto newhall = hall;
                            auto newA = roomA;
                            newhall[i] = NONE;
                            newA.push(A);
                            out[BurrowState<N>{newhall,newA, roomB, roomC, roomD}] = 
                                ((i - getRoomEntrance(A)) + N - roomA.fill) * getAmphipodEnergy(A);
                        }
                    }
                }
                break;
            case B:
                if(roomB.onlyContains(B)) {
                    if(i < getRoomEntrance(B)) {
                        bool freepath = true;
                        for(int j = i + 1; j <= getRoomEntrance(B); j++) {
                            if(hall[j] != NONE && hall[j] != FORBIDDEN) {
                                freepath = false;
                                break;
                            }
                        }
                        if(freepath) {
                            auto newhall = hall;
                            auto newB = roomB;
                            newhall[i] = NONE;
                            newB.push(B);
                            out[BurrowState<N>{newhall,roomA, newB, roomC, roomD}] = 
                                ((getRoomEntrance(B) - i) + N - roomB.fill) * getAmphipodEnergy(B);
                        }
                    }
                    else {
                        bool freepath = true;
                        for(int j = i - 1; j >= getRoomEntrance(B); j--) {
                            if(hall[j] != NONE && hall[j] != FORBIDDEN) {
                                freepath = false;
                                break;
                            }
                        }
                        if(freepath) {
                            auto newhall = hall;
                            auto newB = roomB;
                            newhall[i] = NONE;
                            newB.push(B);
                            out[BurrowState<N>{newhall,roomA, newB, roomC, roomD}] = 
                                ((i - getRoomEntrance(B)) + N - roomB.fill) * getAmphipodEnergy(B);
                        }
                    }
                }
                break;
            case C:
                if(roomC.onlyContains(C)) {
                    if(i < getRoomEntrance(C)) {
                        bool freepath = true;
                        for(int j = i + 1; j <= getRoomEntrance(C); j++) {
                            if(hall[j] != NONE && hall[j] != FORBIDDEN) {
                                freepath = false;
                                break;
                            }
                        }
                        if(freepath) {
                            auto newhall = hall;
                            auto newC = roomC;
                            newhall[i] = NONE;
                            newC.push(C);
                            out[BurrowState<N>{newhall,roomA, roomB, newC, roomD}] = 
                                ((getRoomEntrance(C) - i) + N - roomC.fill) * getAmphipodEnergy(C);
                        }
                    }
                    else {
                        bool freepath = true;
                        for(int j = i - 1; j >= getRoomEntrance(C); j--) {
                            if(hall[j] != NONE && hall[j] != FORBIDDEN) {
                                freepath = false;
                                break;
                            }
                        }
                        if(freepath) {
                            auto newhall = hall;
                            auto newC = roomC;
                            newhall[i] = NONE;
                            newC.push(C);
                            out[BurrowState<N>{newhall,roomA, roomB, newC, roomD}] = 
                                ((i - getRoomEntrance(C)) + N - roomC.fill) * getAmphipodEnergy(C);
                        }
                    }
                }
                break;
            case D:
                if(roomD.onlyContains(D)) {
                    if(i < getRoomEntrance(D)) {
                        bool freepath = true;
                        for(int j = i + 1; j <= getRoomEntrance(D); j++) {
                            if(hall[j] != NONE && hall[j] != FORBIDDEN) {
                                freepath = false;
                                break;
                            }
                        }
                        if(freepath) {
                            auto newhall = hall;
                            auto newD = roomD;
                            newhall[i] = NONE;
                            newD.push(D);
                            out[BurrowState<N>{newhall,roomA, roomB, roomC, newD}] = 
                                ((getRoomEntrance(D) - i) + N - roomD.fill) * getAmphipodEnergy(D);
                        }
                    }
                    else {
                        bool freepath = true;
                        for(int j = i - 1; j >= getRoomEntrance(D); j--) {
                            if(hall[j] != NONE && hall[j] != FORBIDDEN) {
                                freepath = false;
                                break;
                            }
                        }
                        if(freepath) {
                            auto newhall = hall;
                            auto newD = roomD;
                            newhall[i] = NONE;
                            newD.push(D);
                            out[BurrowState<N>{newhall,roomA, roomB, roomC, newD}] = 
                                ((i - getRoomEntrance(D)) + N - roomD.fill) * getAmphipodEnergy(D);
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
    return out;
}

template <int N>
int dijkstra(BurrowState<N> initial) {
    std::map<BurrowState<N>, int> dists;

    // Use a priority queue of yet to check new adj nodes. Pairs are loc,dist to allow for sorting
    std::priority_queue< std::pair<int,BurrowState<N>>, std::vector<std::pair<int,BurrowState<N>>> , std::greater<std::pair<int,BurrowState<N>>> > q;   
    q.push(std::make_pair(0, initial));
    dists[initial] = 0;

    while (!q.empty()) {
        // Grab the next node with smallest distance from start
        BurrowState<N> u = q.top().second;
        q.pop();
        if(u.isAllHome()) { // win
            return dists[u];
        }

        /// Check all possible adjacents for shorter paths
        for (auto const& [v, dist]: u.getNeighbours()) {
            int alt = dists[u] + dist;
            if(dists.find(v) == dists.end())  { dists[v] = std::numeric_limits<int>::max(); }
            if (alt < dists[v]) {
                dists[v] = alt;
                q.push(std::make_pair(alt, v));
            }
        };

    }      
    return 0;       
}

std::pair<unsigned int,unsigned int> Burrow::getMinEnergy() {
    return {dijkstra(m_initial_1),dijkstra(m_initial_2)};
}