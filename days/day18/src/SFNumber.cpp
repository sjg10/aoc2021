#include <iostream>
#include <vector>
#include <variant>
#include <memory>
#include <sstream>
#include "SFNumber.h"


const int SFNumber::OPEN_PAIR = -1;
const int SFNumber::CLOSE_PAIR = -2;
const int SFNumber::COMMA = -3;

/** Reduce the SFNumber according to the problem rules */
void SFNumber::reduce() {
    bool edited = true;
    while(edited) {
        int depth = 0;
        edited = false;
        int split_idx = -1;
        for(unsigned int i = 0; i < m_array.size(); i++) {
            if (m_array[i] == OPEN_PAIR) {
                depth++;
                if(depth == 5) { // this pair is nested in 4 previous pairs
                    //explode
                    int lval = m_array[i + 1];
                    int rval = m_array[i + 3];
                    for(int j=i - 1; j>=0; j--) {
                        if(m_array[j] >= 0) {
                            m_array[j] += lval;
                            break;
                        }
                    }
                    for(unsigned int j=i + 4; j < m_array.size(); j++ ) {
                        if(m_array[j] >= 0) {
                            m_array[j] += rval;
                            break;
                        }
                    }
                    m_array[i] = 0;
                    m_array.erase(m_array.begin() + i + 1, m_array.begin() + i + 5);
                    edited = true;
                    break;
                }
            }
            else if(m_array[i] == CLOSE_PAIR) {
                depth--;
            }
            else if(m_array[i]>=10) {
                if (split_idx == -1) {split_idx = i;}; // record leftmost position requiring split
               
            }
        }
        if(!edited && split_idx >= 0) { // only split if nothing explodes
            // split
            int lval = m_array[split_idx] / 2;
            int rval = (m_array[split_idx] + 1) / 2;

            m_array[split_idx] = OPEN_PAIR;
            std::array<int,4> new_array = {lval, COMMA, rval, CLOSE_PAIR};
            m_array.insert(m_array.begin() + split_idx + 1, new_array.begin(), new_array.end());
            edited = true;
        }
    }
}


std::ostream& operator<<(std::ostream& os, const SFNumber& n) {
    for(auto const &c: n.m_array) {
        if(c >= 0) {os << c;}
        else if(c == SFNumber::OPEN_PAIR) {os << "[";}
        else if(c == SFNumber::CLOSE_PAIR) {os << "]";}
        else if(c == SFNumber::COMMA) {os << ",";}
    }
    return os;
}

unsigned int SFNumber::magnitude() {
    std::vector<std::pair<int, int>> counter;
    for(auto const &c: m_array) {
        if(c == OPEN_PAIR) {
            counter.push_back(std::make_pair(-1,-1));
        }
        else if(c == CLOSE_PAIR) {
            int out = (counter.back().first * 3) + (counter.back().second * 2);
            counter.pop_back();
            if(counter.empty()) return out;
            if (counter.back().first == -1) { 
                counter.back().first = out;
            }
            else {
                counter.back().second = out;
            }
        }
        else if(c != COMMA) {
            if (counter.back().first == -1) { 
                counter.back().first = c;
            }
            else {
                counter.back().second = c;
            }
        }
    }
    return 0;
}

void SFNumber::radd(const SFNumber &n) {
    m_array.insert(m_array.begin(), OPEN_PAIR);
    m_array.push_back(COMMA);
    m_array.insert( m_array.end(), n.m_array.begin(), n.m_array.end());
    m_array.push_back(CLOSE_PAIR);
    reduce();
}

SFNumber::SFNumber(std::string input) {
    m_array = {};
    for (auto const &c: input) {
        if (c == '[') {m_array.push_back(OPEN_PAIR);}
        else if (c == ']') {m_array.push_back(CLOSE_PAIR);}
        else if (c == ',') {m_array.push_back(COMMA);}
        else {m_array.push_back(c - '0');}
    }
    reduce();
}