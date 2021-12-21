#include <iostream>
#include <map>
#include <stack>
#include <algorithm>
#include "Day10.h"


std::vector<std::string> Day10::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = getSyntax(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned int, unsigned long int> Day10::getSyntax(std::istream &input) {
    std::stack<char> stack;
    const std::map<char,char> matches = {{'(',')'},{'[',']'},{'{','}'},{'<','>'}};
    const std::map<char,unsigned int> part1_points = {{')',3},{']',57},{'}',1197},{'>',25137}};
    const std::map<char,unsigned int> part2_points = {{')',1},{']',2},{'}',3},{'>',4}};
    unsigned int part1 = 0;
    std::vector<unsigned long int> corrupt_scores;
    char c;
    bool corrupt = false;
    while(input.get(c)) {
        if (c == '\n') {
            if(!corrupt) {
                //incomplete line
                unsigned long int score = 0;
                for (;!stack.empty(); stack.pop()) {
                    score *= 5;
                    score += part2_points.at(matches.at(stack.top()));
                }
                corrupt_scores.push_back(score);
            }
            std::stack<char>().swap(stack); // reset stack
            corrupt = false; 
        }
        else {
            if (corrupt) {continue;}
            else if (c == '(' || c == '[' || c == '{' || c == '<') {
                stack.push(c);
            }
            else {
                auto c2 = stack.top();
                if(matches.at(c2) != c) {
                    //corrupt line
                    corrupt = true;
                    part1 += part1_points.at(c);
                }
                else { // good line closure
                    stack.pop();
                }
            }
        }
    }

    // Partially sort corrupt_scores to get median (Assume odd length)
    std::nth_element(corrupt_scores.begin(), corrupt_scores.begin()+corrupt_scores.size() / 2, corrupt_scores.end());
    return  {part1, corrupt_scores[corrupt_scores.size() / 2]};
}