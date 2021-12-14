#include "Polymer.h"
#include <algorithm>
#include <iostream>

Polymer::Polymer(const std::string &initial) {
    m_left_char = initial[0];
    m_right_char = initial[initial.size() - 1];
    m_polymer_pairs = {};
    m_polymer_rules = {};
    // Save the pairs that have been read
    for(unsigned int i = 1; i < initial.size(); i++) {
        std::pair<char, char> pair = std::make_pair(initial.at(i - 1), initial.at(i));
        if(!m_polymer_pairs.count(pair)) {
            m_polymer_pairs[pair] = 0;
        }
        m_polymer_pairs[pair]++;
    }
}

void Polymer::addRule(char first, char second, char middle) {
    std::pair<char, char> search_pair = std::make_pair(first, second);
    std::pair<char, char> new_pair1 = std::make_pair(first, middle);
    std::pair<char, char> new_pair2 = std::make_pair(middle, second);
    m_polymer_rules[search_pair] = {new_pair1, new_pair2};
}

void Polymer::expand() {
    std::map<std::pair<char, char>, unsigned long int> new_polymer_pairs;
    for (auto const &m: m_polymer_pairs) { // For each old pair
        try { // if remapped
            auto new_pairs = m_polymer_rules[m.first];
            for(auto const &new_pair: new_pairs ) { // for each pair created from the old pair
                if(!new_polymer_pairs.count(new_pair)) {
                    new_polymer_pairs[new_pair] = 0;
                }
                 // add as many new pairs as there were old pairs
                new_polymer_pairs[new_pair]+=m.second;
            }
        }
        catch (const std::out_of_range &e) { // pair was not remapped
            if(!new_polymer_pairs.count(m.first)) {
                new_polymer_pairs[m.first] = 0;
            }
            new_polymer_pairs[m.first]+=m.second; // keep the old pair count
        }
    }
    m_polymer_pairs = std::move(new_polymer_pairs);
}

unsigned long int Polymer::getMeasure() const {
    std::map<char, unsigned long int> ingredient_count;
    for(auto const &m : m_polymer_pairs) { // Translate a count of pairs into a count of single chars
        if(!ingredient_count.count(m.first.first)) {
            ingredient_count[m.first.first] = 0;
        }
        if(!ingredient_count.count(m.first.second)) {
            ingredient_count[m.first.second] = 0;
        }
        ingredient_count[m.first.first] += m.second;
        ingredient_count[m.first.second] += m.second;
    }
    // Now note that all letters have now been double counted except the left char and right char once
    for(auto const &m : ingredient_count) {
        ingredient_count[m.first] /= 2;
    }
    ingredient_count[m_left_char]++;
    ingredient_count[m_right_char]++;

    //Find the largest and smallest counts
    auto mm = std::minmax_element(ingredient_count.begin(), ingredient_count.end(), 
        [](const auto &a, const auto &b) { return a.second < b.second;});
    return mm.second->second - mm.first->second;
}