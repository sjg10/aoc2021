#pragma once
#include <map>
#include <vector>
#include <set>
#include <string>

/** Store a polymer and manipulate */
class Polymer {
    public:
        /** Create a polymer from the starting chain */
        Polymer(const std::string &initial);
        /** Register a permutation insertion rule */
        void addRule(char first, char second, char middle);
        /** Apply all the rules once */
        void expand();
        /** Get the measure i.e. most common ingredient count - least common count */
        unsigned long int getMeasure() const;
    private:
        std::map<std::pair<char, char>, unsigned long int> m_polymer_pairs; //store the pairs not the string to save memory and compute
        std::map<std::pair<char, char>, std::vector<std::pair<char, char>>> m_polymer_rules;
        char m_left_char; // used for counting
        char m_right_char;// used for counting
};