#include <iostream>
#include <fstream>
#include <algorithm>
#include "Display.h"


Display::Display(std::vector<std::set<char>> observed) {
    findDecoding(observed);
}

/** Test the sizeof the intersection of two sets */
unsigned int Display::intersectionSize(const std::set<char> &a, const std::set<char> &b) {
    std::vector<int> intersection;
    std::set_intersection(a.begin(), a.end(),
                          b.begin(), b.end(),
                          std::back_inserter(intersection));
    return intersection.size();
}

/** Using an array of 10 different observed digits deduce which was which */
void Display::findDecoding(std::vector<std::set<char>> observed) {
    m_decoded = std::vector<std::set<char>>(10, std::set<char>({}));
    // Extract the constant length letters
    for(auto const &o: observed) {
        if (o.size() == 2) {
            m_decoded[1] = o;
        } else if (o.size() == 4) {
            m_decoded[4] = o;
        } else if (o.size() == 3) {
            m_decoded[7] = o;
        } else if (o.size() == 7) {
            m_decoded[8] = o;
        }
    }

    for(auto const &o: observed) {
        if (o.size() == 6) {
            // if intersection with one is size 1 then is 6
            if(m_decoded[6].empty() && intersectionSize(o, m_decoded[1]) == 1) {
                m_decoded[6] = o;
            }
            // if intersection with 4 is size 4 then 9
            else if(m_decoded[9].empty() && intersectionSize(o, m_decoded[4]) == 4) {
                m_decoded[9] = o;
            }
            else { // otherwise 0
                m_decoded[0] = o;
            }
        }
        else if (o.size() == 5) {
            // if intersection with one is size 2 then is 3
            if (m_decoded[3].empty() && intersectionSize(o, m_decoded[1]) == 2) {
                m_decoded[3] = o;
            }
            // if intersection with 4 is size 2 then 2
            else if (m_decoded[2].empty() && intersectionSize(o, m_decoded[4]) == 2) {
                m_decoded[2] = o;
            }
            else { // otherwise 5
                m_decoded[5] = o;
            }
        }
    }
}

unsigned int Display::decodeDigits(std::vector<std::set<char>> observed) {
    unsigned int mult = 1;
    unsigned int out = 0;
    for(int i = observed.size() - 1; i >= 0; i--) {
        auto idx = std::find(m_decoded.begin(), m_decoded.end(), observed[i]);
        if (idx == m_decoded.end()) {
            throw std::runtime_error("Unrecognised character");
        }
        unsigned int idxi = idx - m_decoded.begin();
        out += idxi * mult;
        mult *= 10;
    }
    return out;
}