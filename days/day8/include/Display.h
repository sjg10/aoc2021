#pragma once
#include <vector>
#include <set>

class Display{
    public:
        /** Construct a display from an observed list of 10 digits */
        Display(std::vector<std::set<char>> observed);
        /** Translate an observed n digit number to its true integer value */
        unsigned int decodeDigits(std::vector<std::set<char>> observed);
    private:
        void findDecoding(std::vector<std::set<char>> observed);
        static unsigned int intersectionSize(const std::set<char> &a, const std::set<char> &b);
        std::vector<std::set<char>> m_decoded;
};