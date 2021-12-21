#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include "Day15.h"


std::vector<std::string> Day15::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getPaths(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

// /** Find the shortest distance from top right to bottom left */
// int dijkstra(const std::vector<int> &weights) {
//     int s = sqrt(weights.size());
//     std::vector<int> dists(s*s, std::numeric_limits<int>::max());
//     std::vector<bool> visited(s*s, false); // so we dont readd already checked nodes.


//     visited[0] = true;
//     dists[0] = 0;
    
//     std::list<int> q; // nodes to check that have <  std::numeric_limits<int>::max() dist
//     q.push_back(0);
//     while (!q.empty()) {
//         /*int min_dist = std::numeric_limits<int>::max();
//         int u = 0;
//         for(auto const &w: q) {
//             if(dists[w] <= min_dist) {
//                 min_dist = dists[w];
//                 u = w;
//             }
//         }*/

//         std::list<int>::iterator it = std::min_element(q.begin(), q.end(), [&dists](const int &a, const int &b) {
//             return dists[a] < dists[b];
//         });
//         int u = *it;
//         q.erase(it);
//         if(u == (s * s) - 1) {
//             return dists[u];
//         }
//         int x = u % s;
//         int y = u / s;
//         if (x > 0) { // left
//             int v = u - 1;
//             if(!visited[v]) {
//                 int alt = dists[u] + weights.at(v);
//                 if (alt < dists[v]) {
//                     visited[v] = true;
//                     q.push_back(v);
//                     dists[v] = alt;
//                 }
//             }
//         }
//         if (x < s - 1) { // right
//             int v = u + 1;
//             if(!visited[v]) {
//                 int alt = dists[u] + weights.at(v);
//                 if (alt < dists[v]) {
//                     visited[v] = true;
//                     q.push_back(v);
//                     dists[v] = alt;
//                 }
//             }
//         }
//         if (y > 0) { // up
//             int v = u - s;
//             if(!visited[v]) {
//                 int alt = dists[u] + weights.at(v);
//                 if (alt < dists[v]) {
//                     visited[v] = true;
//                     q.push_back(v);
//                     dists[v] = alt;
//                 }
//             }
//         }
//         if (y < s - 1) { // down
//             int v = u + s;
//             if(!visited[v]) {
//                 int alt = dists[u] + weights.at(v);
//                 if (alt < dists[v]) {
//                     visited[v] = true;
//                     q.push_back(v);
//                     dists[v] = alt;
//                 }
//             }
//         }
//     }      
//     return 0;       
// }

/** Find the shortest distance from top right to bottom left */
int dijkstra(const std::vector<int> &weights) {
    int s = sqrt(weights.size());
    std::vector<int> dists(s*s, std::numeric_limits<int>::max());
    dists[0] = 0;

    // Use a priority queue of yet to check new adj nodes. Pairs are loc,dist to allow for sorting
    std::priority_queue< std::pair<int,int>, std::vector<std::pair<int,int>> , std::greater<std::pair<int,int>> > q;   
    q.push(std::make_pair(dists[0], 0));

    while (!q.empty()) {
        // Grab the next node with smallest distance from start
        int u = q.top().second;
        q.pop();
        if(u == (s * s) - 1) {
            return dists[u];
        }

        /// Check all 4 possible adjacents for shorter paths
        int x = u % s;
        int y = u / s;
        if (x > 0) { // left
            int v = u - 1;
            int alt = dists[u] + weights.at(v);
            if (alt < dists[v]) {
                dists[v] = alt;
                q.push(std::make_pair(alt, v));
            }
        }
        if (x < s - 1) { // right
            int v = u + 1;
            int alt = dists[u] + weights.at(v);
            if (alt < dists[v]) {
                dists[v] = alt;
                q.push(std::make_pair(alt, v));
            }
        }
        if (y > 0) { // up
            int v = u - s;
            int alt = dists[u] + weights.at(v);
            if (alt < dists[v]) {
                dists[v] = alt;
                q.push(std::make_pair(alt, v));
            }
        }
        if (y < s - 1) { // down
            int v = u + s;
            int alt = dists[u] + weights.at(v);
            if (alt < dists[v]) {
                dists[v] = alt;
                q.push(std::make_pair(alt, v));
            }
        }
    }      
    return 0;       
}
/** Given a map and an integer m multiply the map up by m */
std::vector<int> multiplyMap(const std::vector<int> &map, int m) {
    int s = sqrt(map.size());
    std::vector<int> largemap(s * s * m * m, 0);
    for(int x = 0; x < s; x++) {
    for(int y = 0; y < s; y++) { // for each entry in the old map
        int u = map.at(x + (y * s));
        for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) { // generate the m^2 entries in the new map
            int newval = (((u - 1) + (i + j)) % 9) + 1; // calculate rollover
            int newx = (i * s) + x;
            int newy = (j * s) + y;
            largemap[newx + (newy * m * s)] = newval;
        }
        }
    }
    }
    return largemap;
}

std::pair<unsigned int, unsigned int> Day15::getPaths(std::istream &input) {
    std::vector<int> map;
    for(std::string read_line; std::getline(input, read_line);) {
        std::transform(read_line.begin(), read_line.end(), std::back_inserter(map),
                    [](unsigned char c){ return c - '0'; });
    }
    return  {dijkstra(map), dijkstra(multiplyMap(map,5))};
}