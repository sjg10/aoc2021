#include "Scanner.h"
#include <queue>
#include <future>

/** Rotate and then translate a point */
Point transformPoint(const Point &p, const Rotation &rotation, const Translation &translation) {
    Point pt;
    pt[0] = (rotation.xmap[0] * p[0] + rotation.xmap[1] * p[1] + rotation.xmap[2] * p[2]) + translation[0];
    pt[1] = (rotation.ymap[0] * p[0] + rotation.ymap[1] * p[1] + rotation.ymap[2] * p[2]) + translation[1];
    pt[2] = (rotation.zmap[0] * p[0] + rotation.zmap[1] * p[1] + rotation.zmap[2] * p[2]) + translation[2];
    return pt;
}

/** Rotate a point */
Point rotatePoint(const Point &p, const Rotation &rotation) {
    Point pt;
    pt[0] = (rotation.xmap[0] * p[0] + rotation.xmap[1] * p[1] + rotation.xmap[2] * p[2]);
    pt[1] = (rotation.ymap[0] * p[0] + rotation.ymap[1] * p[1] + rotation.ymap[2] * p[2]);
    pt[2] = (rotation.zmap[0] * p[0] + rotation.zmap[1] * p[1] + rotation.zmap[2] * p[2]);
    return pt;
}

/** Translate a point */
Point translatePoint(const Point &p, const Translation &translation) {
    Point pt = p;
    pt[0] += translation[0];
    pt[1] += translation[1];
    pt[2] += translation[2];
    return pt;
}


Scanner::Scanner(std::istream &input) {
    m_beacons = {};
    std::string read_line;
    std::getline(input, read_line);
    m_name = std::stoul(read_line.substr(12,2));
    while(std::getline(input, read_line)) {
        if(read_line.empty()) {break;}
        else {
            auto first_sep = read_line.find(",");
            auto second_sep = read_line.find(",", first_sep + 1);
            int x = std::stoi(read_line.substr(0, first_sep));
            int y = std::stoi(read_line.substr(first_sep + 1, second_sep - first_sep));
            int z = std::stoi(read_line.substr(second_sep + 1));
            m_beacons.push_back(Point({x,y,z}));
        }
    };
}

/** Get the path from this scanner to zero (by name) */
std::vector<int> Scanner::getPathToZero() const {
    std::set<unsigned int> visited;
    visited.insert(m_name);
    std::queue<std::pair<const Scanner *, std::vector<int>>> queue;
    queue.push(std::make_pair(this, std::vector<int>()));
    while(!queue.empty()) {
        auto v = queue.front();
        queue.pop();
        for(unsigned int i = 0; i < v.first->m_reference.size(); i++)  {
            auto w = v.first->m_reference[i];
            if(visited.count(w->m_name) == 0) {
                if(w->m_name == 0) {
                    v.second.push_back(i);
                    return v.second; // success
                }
                else {
                    visited.insert(w->m_name);
                    std::vector<int> new_path(v.second);
                    new_path.push_back(i);
                    // Add the node and the path to it into the queue.
                    queue.push(make_pair(w, new_path));
                }
            }
        }
    }
    return std::vector<int>(); // failed!
}


/** Retreive the beacons as seen from point 0 (and the scanner loc). Requires path to 0 */
std::pair<std::vector<Point>,Point> Scanner::getCanonicalBeacons() {
    auto s = this;
    std::vector<Point> out = m_beacons;
    Point loc = {0,0,0};
    if(m_name == 0) { return {out,loc};} //already canonical

    auto path = getPathToZero();
    if(path.empty()) {
        throw std::runtime_error("no path to zero for " + std::to_string(m_name));
    }

    for(int next : path) {
        // apply s->m_rotation and s->m_translation to out
        for(unsigned int i = 0; i < out.size(); i++) {
            out[i] = transformPoint(out[i], s->m_rotation[next], s->m_translation[next]);
        }
        // and update the current scanner location
        loc = transformPoint(loc, s->m_rotation[next], s->m_translation[next]);
        s = s->m_reference[next];
    }
    return {out, loc};
}

/** Update m_reference with overlapping scanners from scanners */
void Scanner::findRemappings(std::vector<Scanner> &scanners) {
    for(auto &scanner: scanners)  {
        //try and map this scanner onto scanner
        if (scanner.m_name == m_name) {continue;}
        for(auto const &rotation: ROTATIONS) { //for each possible rotation
            // for each possible translation
            std::vector<Point> cur_beacons = m_beacons;
            std::transform(cur_beacons.begin(), cur_beacons.end(), cur_beacons.begin(),
                [rotation](Point p) { return rotatePoint(p,rotation);});
            bool found = false;
            for(auto const &from_beacon: cur_beacons) {
                for(auto const &to_beacon: scanner.m_beacons) {
                    Translation translation = {
                        to_beacon[0] - from_beacon[0],
                        to_beacon[1] - from_beacon[1],
                        to_beacon[2] - from_beacon[2]};
                    int overlap = 0;
                    for(auto const &b: cur_beacons) {
                        if(std::find(scanner.m_beacons.begin(),
                            scanner.m_beacons.end(),
                            translatePoint(b, translation)) != scanner.m_beacons.end()) {
                            if (++overlap == 12) { // success
                                m_rotation.push_back(rotation);
                                m_translation.push_back(translation);
                                m_reference.push_back(&scanner);
                                found = true;
                                break;
                            }
                        }
                    }
                    if(found) { break; }
                }
            if(found) { break; }
            }
        }
    }
}

std::pair<std::set<Point>,std::vector<Point>> Scanner::getAllBeacons(std::vector<Scanner> scanners) {

    std::vector<std::future<void>> futures;
    for(auto &scanner: scanners) {
        if(scanner.m_name == 0) { continue; }
        futures.push_back(std::async(std::launch::async, [&scanner, &scanners]() {
            scanner.findRemappings(scanners);
        }));
    }
    for(auto &future: futures) {
        future.wait();
    }
    std::set<Point> out1;
    std::vector<Point> out2;
    for(auto &scanner: scanners) {
        auto can = scanner.getCanonicalBeacons();
        std::copy(can.first.begin(), can.first.end(), std::inserter(out1, out1.end()));
        out2.push_back(can.second);
    }
    return std::make_pair(out1,out2);
}


unsigned int Scanner::getMaxManhattanDistance(const std::vector<Point> &points) {
    unsigned int max_dist = 0;
    for(auto const &aloc: points) {
    for(auto const &bloc: points) {
        unsigned int dist = std::abs(aloc[0] - bloc[0]) +
            std::abs(aloc[1] - bloc[1]) +
            std::abs(aloc[2] - bloc[2]);
        if (dist > max_dist) { max_dist = dist;}
    }
    }    
    return max_dist;
}