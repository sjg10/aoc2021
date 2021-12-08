#include <iostream>
#include <fstream>
#include <algorithm>
#include "Day3.h"


std::vector<std::string>  Day3::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    out.push_back(std::to_string(getPowerConsumption(is1)));

    std::ifstream is2(res_files[0]);
    if(is2.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    out.push_back(std::to_string(getLifeSupportRating(is2)));
    return out;
}

unsigned int Day3::getPowerConsumption(std::istream &status) {
    std::vector<int> zeros_count = {};
    for(std::string read_string; std::getline(status, read_string);) {
        if(!zeros_count.size()) {
            for(auto const &ch: read_string) {
                if (ch == '0') {zeros_count.push_back(1);}
                else if (ch == '1') { zeros_count.push_back(-1);}
                else { throw std::runtime_error("Unknown char" + ch); }
            }
        }
        else {
            for(unsigned int i = 0; i < read_string.size(); i++) {
                if (read_string[i] == '0') {zeros_count[i]++;}
                else if (read_string[i] == '1') { zeros_count[i]--;}
                else { throw std::runtime_error("Unknown char" + read_string[i]); }
            }
        }
    }
    unsigned int gamma = 0;
    unsigned int delta = 0;
    for(unsigned int i = 0; i < zeros_count.size(); i++) {
        gamma += (zeros_count[zeros_count.size() - (i + 1)] > 0 ? 0 : 1) << i;
        delta += (zeros_count[zeros_count.size() - (i + 1)] < 0 ? 0 : 1) << i;
    }

    return gamma * delta;
}


unsigned int Day3::getLifeSupportRating(std::istream &status) {
    int zeros_count_oxygen = 0;
    int zeros_count_c02 = 0;
    std::vector<std::string> oxygen_entries;
    std::vector<std::string> c02_entries;
    // read in values and store them (as well as 0 offset zero count)
    for(std::string read_string; std::getline(status, read_string);) {
            if (read_string[0] == '0') {zeros_count_oxygen++;}
            else if (read_string[0] == '1') { zeros_count_oxygen--;}
            else { throw std::runtime_error("Unknown char" + read_string[0]); }
            oxygen_entries.push_back(read_string);
    }
    // copy to c02
    zeros_count_c02 = zeros_count_oxygen;
    c02_entries = oxygen_entries;
    unsigned int word_length = oxygen_entries[0].size();
    for (unsigned int idx = 0; idx < word_length; idx++) {

        oxygen_entries.erase(std::remove_if(oxygen_entries.begin(), 
                            oxygen_entries.end(),
                            [zeros_count_oxygen, idx](std::string s){
                                if (zeros_count_oxygen >  0) { return s[idx] == '1';}
                                else { return s[idx] == '0';}
                            }),oxygen_entries.end());
        if(idx == word_length - 1 || oxygen_entries.size() <= 1) {
            break;
        }
        zeros_count_oxygen = 0;
        for(unsigned int i = 0; i < oxygen_entries.size(); i++) {
            if (oxygen_entries[i][idx + 1] == '0') {zeros_count_oxygen++;}
            else if (oxygen_entries[i][idx + 1] == '1') { zeros_count_oxygen--;}
            else { throw std::runtime_error("Unknown char" + oxygen_entries[i][idx + 1]); }
        }
    }
    for (unsigned int idx = 0; idx < word_length; idx++) {
        c02_entries.erase(std::remove_if(c02_entries.begin(), 
                            c02_entries.end(),
                            [zeros_count_c02, idx](std::string s){
                                if (zeros_count_c02 >  0) { return s[idx] == '0';}
                                else { return s[idx] == '1';}
                            }),c02_entries.end());
        if(idx == word_length - 1 || c02_entries.size() <= 1) {
            break;
        }
        zeros_count_c02 = 0;
        for(unsigned int i = 0; i < c02_entries.size(); i++) {
            if (c02_entries[i][idx + 1] == '0') {zeros_count_c02++;}
            else if (c02_entries[i][idx + 1] == '1') { zeros_count_c02--;}
            else { throw std::runtime_error("Unknown char" + c02_entries[i][idx + 1]); }
        }
    }
    unsigned int oxygen_score = 0;
    unsigned int c02_score = 0;
    for(unsigned int i = 0; i < word_length; i++) {
        oxygen_score += (oxygen_entries[0][word_length - (i + 1)] == '0' ? 0 : 1) << i;
        c02_score += (c02_entries[0][word_length - (i + 1)] == '0' ? 0 : 1) << i;
    }
    return oxygen_score * c02_score;
}
