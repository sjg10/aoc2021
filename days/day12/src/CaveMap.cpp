#include "CaveMap.h"
#include <algorithm>

CaveMap::CaveMap(const std::string &start) {
    /** Create the start vertex first to ensure it has index 0 */
    addVertex(start);
    m_single_paths = 0;
    m_double_paths = 0;
}

void CaveMap::addEdge(const std::string &src, const std::string &dest) {
    if(!m_name_map.count(src)) { // add src if it doesnt exist
        addVertex(src);
    }
    if(!m_name_map.count(dest)) { // add dest if it doesnt exist
        addVertex(dest);
    }
    // add the neighbours
    m_neighbours[m_name_map[src]].insert(m_name_map[dest]);
    m_neighbours[m_name_map[dest]].insert(m_name_map[src]);
}

/** Assume a vertex doesnt exist yet and create it */
void CaveMap::addVertex(const std::string &src) {
    m_name_map[src] = m_neighbours.size();
    m_neighbours.push_back({}); // no neighbours yet
    // Check if small cave
    m_small_cave.push_back(std::all_of(src.begin(), src.end(), [](unsigned char c) {return std::islower(c);}));
}

std::pair<unsigned int,unsigned int> CaveMap::getPaths(const std::string &start, const std::string &end) {
    getPartialPaths(m_name_map[start], m_name_map[end], std::vector<bool>(m_neighbours.size(),false), false);
    return {m_single_paths, m_single_paths + m_double_paths};
}


/** Count the paths from src to dest (recursively) using the vertices in map.
 * Recursively use visited to prevent double visits of small caves and start
 * Except for one small (non start) double visit if double_visit is false
 * Updates m_single_paths and m_double_paths
 */
void CaveMap::getPartialPaths(unsigned int src, unsigned int dest, std::vector<bool> visited, bool double_visited) {
    visited[src] = true;
    for(auto const &next : m_neighbours[src]) {
        if (dest == next) {
            if (double_visited) {m_double_paths++;}
            else {m_single_paths++;}
        }
        else if (!m_small_cave[next] || !visited[next]) {
            // large cave or unvisited small cave
            getPartialPaths(next, dest, visited, double_visited);
        }
        else if (!double_visited && next != START) {
            // double visit a small visited cave
            getPartialPaths(next, dest, visited, true);
        }
    }
}