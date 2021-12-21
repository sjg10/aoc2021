#include <iostream>
#include <map>
#include "Day21.h"
#include "Game.h"


std::vector<std::string> Day21::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = findScore(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}



std::pair<unsigned int, unsigned long int> Day21::findScore(std::istream &input) {
    std::string line;
    std::getline(input,line);
    unsigned int p1_start = line[28] - '0';
    std::getline(input,line);
    unsigned int p2_start = line[28] - '0';

    auto game = Game(p1_start, p2_start);
    auto part1 = game.playGame();
    auto part2 = game.playQuantumGame();
    return {part1, std::max(part2.first, part2.second)};
}
