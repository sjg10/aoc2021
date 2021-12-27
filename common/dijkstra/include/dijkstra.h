#pragma once
#include <functional>
#include <queue>

/** Using dijkstra find the shortest path from start to the first success of win(), using the mpa of neighbours to distances */
template <typename T>
unsigned int dijkstra(const T &start, std::function<bool(T*)> win, std::function<std::map<T,unsigned int>(T*)> neighbours) {
    std::map<T,unsigned int> dists;
    dists[start] = 0;

    // Use a priority queue of yet to check new adj nodes. Pairs are loc,dist to allow for sorting
    std::priority_queue< std::pair<unsigned int,T>, std::vector<std::pair<unsigned int,T>> , std::greater<std::pair<unsigned int,T>> > q;   
    q.push(std::make_pair(dists.at(start), start));

    while (!q.empty()) {
        // Grab the next node with smallest distance from start
        T u = q.top().second;
        q.pop();
        if(win(&u)) {
            return dists[u];
        }

        /// Check all nbors
        for(auto const &[v,dist]: neighbours(&u)) {
            unsigned int alt = dists[u] + dist;
            if(dists.find(v) == dists.end()) {dists[v] = std::numeric_limits<int>::max();}
            if (alt < dists[v]) {
                dists[v] = alt;
                q.push(std::make_pair(alt, v));
            }
        }
    }      
    return 0;       
}