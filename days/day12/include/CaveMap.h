#pragma once
#include <map>
#include <vector>
#include <string>
#include <set>

/** Map of caves that remaps names to contiguous ints to allow vectorisation speed up */
class CaveMap{
    public:
        /** Create a cavemap with the start node named start */
        CaveMap(const std::string &start);
        /** Add an edge between two caves */
        void addEdge(const std::string &src, const std::string &dest);
        /* Count the number of paths from start to end using part 1 and part2 rules respectively */
        std::pair<unsigned int, unsigned int> getPaths(const std::string &start, const std::string &end);
    private:
        void addVertex(const std::string &src);
        void getPartialPaths(unsigned int src, unsigned int dest, std::vector<bool> visited, bool double_visited);
        std::map<std::string, unsigned int> m_name_map;
        std::vector<std::set<unsigned int>> m_neighbours;
        std::vector<bool> m_small_cave;
        unsigned int m_single_paths;
        unsigned int m_double_paths;
        static constexpr unsigned int START = 0;
};