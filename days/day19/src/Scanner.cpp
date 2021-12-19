#include "Scanner.h"
#include <queue>
void Beacon::applyRotation(const Rotation &rotation) {
 m_rot_x = rotation.xmap[0] * m_raw_x + rotation.xmap[1] * m_raw_y + rotation.xmap[2] * m_raw_z;
 m_rot_y = rotation.ymap[0] * m_raw_x + rotation.ymap[1] * m_raw_y + rotation.ymap[2] * m_raw_z;
 m_rot_z = rotation.zmap[0] * m_raw_x + rotation.zmap[1] * m_raw_y + rotation.zmap[2] * m_raw_z;
}

void Beacon::applyTranslation(const Translation &translation) {
    m_x = m_rot_x + translation[0];
    m_y = m_rot_y + translation[1];
    m_z = m_rot_z + translation[2];
}

Scanner::Scanner(std::istream &input) {
    m_beacons = {};
    std::string read_line;
    std::getline(input, read_line);
    m_name = std::stoi(read_line.substr(12,2));
    while(std::getline(input, read_line)) {
        if(read_line.empty()) {break;}
        else {
            auto first_sep = read_line.find(",");
            auto second_sep = read_line.find(",", first_sep + 1);
            int x = std::stoi(read_line.substr(0, first_sep));
            int y = std::stoi(read_line.substr(first_sep + 1, second_sep - first_sep));
            int z = std::stoi(read_line.substr(second_sep + 1));
            m_beacons.insert(std::make_shared<Beacon>(x,y,z));
        }
    };
}

/** Get the path from this scanner to zero (by name) */
std::vector<int> Scanner::getPathToZero() const {
    std::set<int> visited;
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
    std::vector<Point> out;
    Point loc = {0,0,0};
    for(auto const &b: m_beacons) { out.push_back({b->m_raw_x, b->m_raw_y, b->m_raw_z});}
    if(m_name == 0) { return {out,loc};} //already canonical

    auto path = getPathToZero();
    if(path.empty()) {
        throw std::runtime_error("no path to zero for " + std::to_string(m_name));
    }

    for(int next : path) {
        // apply s->m_rotation to out
        // apply s->m_translation to out
        for(unsigned int i = 0; i < out.size(); i++) {
            Point b_new = out[i];
            b_new[0] = (s->m_rotation[next].xmap[0] * out[i][0] + s->m_rotation[next].xmap[1] * out[i][1] + s->m_rotation[next].xmap[2] * out[i][2]) +
                s->m_translation[next][0];
            b_new[1] = (s->m_rotation[next].ymap[0] * out[i][0] + s->m_rotation[next].ymap[1] * out[i][1] + s->m_rotation[next].ymap[2] * out[i][2]) +
                s->m_translation[next][1];
            b_new[2] = (s->m_rotation[next].zmap[0] * out[i][0] + s->m_rotation[next].zmap[1] * out[i][1] + s->m_rotation[next].zmap[2] * out[i][2]) +
                s->m_translation[next][2];
            out[i] = b_new;
        }
        //and update the current scanner location
        Point loc_new = loc;
        loc_new[0] = (s->m_rotation[next].xmap[0] * loc[0] + s->m_rotation[next].xmap[1] * loc[1] + s->m_rotation[next].xmap[2] * loc[2]) +
            s->m_translation[next][0];
        loc_new[1] = (s->m_rotation[next].ymap[0] * loc[0] + s->m_rotation[next].ymap[1] * loc[1] + s->m_rotation[next].ymap[2] * loc[2]) +
            s->m_translation[next][1];
        loc_new[2] = (s->m_rotation[next].zmap[0] * loc[0] + s->m_rotation[next].zmap[1] * loc[1] + s->m_rotation[next].zmap[2] * loc[2]) +
            s->m_translation[next][2];
        loc = loc_new;
        s = s->m_reference[next];
    }
    return {out, loc};
}

std::pair<std::set<Point>,std::vector<Point>> Scanner::getAllBeacons(std::vector<Scanner> scanners) {
    unsigned int i = 0;
    unsigned int j = 0;
    for(j = 1; j < scanners.size(); j++) {
    for(i = 0; i < scanners.size(); i++)  {
        //try and map j on to i
        if (i == j) {continue;}
        for(auto const &rotation: ROTATIONS) { //for each possible rotation
            for(auto const &b: scanners[j].m_beacons) {b->applyRotation(rotation);}
            // for each possible translation
            for(auto const &from_beacon: scanners[j].m_beacons) {
            for(auto const &to_beacon: scanners[i].m_beacons) {
                Translation translation = {
                    to_beacon->m_raw_x - from_beacon->m_rot_x,
                    to_beacon->m_raw_y - from_beacon->m_rot_y,
                    to_beacon->m_raw_z - from_beacon->m_rot_z};
                for(auto const &b: scanners[j].m_beacons) {b->applyTranslation(translation);}
                std::set<std::array<int,3>> intersect;
                int inserted = 0;
                for(auto const &b: scanners[j].m_beacons) {
                    intersect.insert({b->m_x, b->m_y, b->m_z});
                    inserted++;
                }
                for(auto const &b: scanners[i].m_beacons) {
                    intersect.insert({b->m_raw_x, b->m_raw_y, b->m_raw_z});
                    inserted++;
                }

                if (inserted - intersect.size() >= 12) {
                    //success!
                    scanners[j].m_rotation.push_back(rotation);
                    scanners[j].m_translation.push_back(translation);
                    scanners[j].m_reference.push_back(&scanners[i]);
                    goto mapped_part; // nasty goto prevents ugly break nesting
                }
            }
            }
        }
        mapped_part:; // for goto
    }
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
