#include <iostream>
#include <fstream>
#include <algorithm>
#include "Day4.h"
#include "BingoCard.h"


std::vector<std::string> Day4::run(std::vector<std::string> res_files) {
    std::vector<std::string> out;
    std::ifstream is1(res_files[0]);
    if(is1.fail()) {throw std::runtime_error("Could not open file " + res_files[0]);}
    auto res = playBingo(is1);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}

std::pair<unsigned int,unsigned int> Day4::playBingo(std::istream &input) {
    // First line is moves 
    std::string moves_line;
    std::getline(input, moves_line);
    // Skip empty line
    std::string read_line;
    std::getline(input, read_line);
    // Build cards
    std::vector<std::unique_ptr<BingoCard>> cards;
    std::vector<std::string> card_builder= {};
    for (;std::getline(input, read_line);) {
        if(read_line.empty()) {
            cards.push_back(std::make_unique<BingoCard>(card_builder));
            card_builder = {};
        }
        else {
            card_builder.push_back(read_line);
        }
    }
    cards.push_back(std::make_unique<BingoCard>(card_builder)); // add final card
    unsigned int first_score = 0;
    unsigned int wins = 0;
    // Play the games
    std::stringstream ss(moves_line);
    for(std::string elmt; std::getline(ss, elmt, ',');) {
        unsigned int turn = std::stoul(elmt);
        for(auto const &card: cards) {
            unsigned int score = card->play(turn);
            if(score > 0) {
                wins++;
                if (wins == 1) { first_score = score;}
                else if (wins == cards.size()) {
                    return {first_score, score};
                }
            }
        }
    }
    return {0, 0}; // something went wrong - one of the cards didnt end!
}