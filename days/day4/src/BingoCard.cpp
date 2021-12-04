#include <iostream>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <deque>
#include "BingoCard.h"

BingoCard::BingoCard(std::vector<std::string> cards) {
    for (auto const &row: cards) {
        std::vector<unsigned int> row_cards = {};
        std::stringstream ss(row);
        for(std::string elmt; std::getline(ss, elmt, ' ');){
            if(elmt.empty()) {continue;} // handle multiple spaces/leading spaces
            row_cards.push_back( std::stoul(elmt) );
        }
        m_card.push_back(row_cards);
        m_found.push_back(std::vector<bool>(row_cards.size(), false));
    }
}

unsigned int BingoCard::play(unsigned int turn) {
    if(!m_score) { // i.e. not finished
        for(unsigned int row_idx = 0; row_idx < m_card.size(); row_idx++) {
            auto col_idx = std::find(m_card[row_idx].begin(), m_card[row_idx].end(), turn);
            if(col_idx != m_card[row_idx].end()) {
                m_found[row_idx][col_idx - m_card[row_idx].begin()] = true;
                if(checkWin()) {
                    computeScore(turn);
                    return m_score;
                }
                else {
                    return 0; // did not win on this turn
                }
            }
        }
    }
    return 0; // no tiles changed so didnt win OR already finished game
}

bool BingoCard::checkWin() {
    //cant use vector<bool> b/c c++ doesnt make that a container!
    std::deque<bool> row_accum(m_found.size(),true);
    std::deque<bool> col_accum(m_found[0].size(),true);
    // check rows
    for (unsigned int row = 0; row < m_found.size(); row++) {
    for (unsigned int col = 0; col < m_found[0].size(); col++) {
        row_accum[row] &= m_found[row][col];
        col_accum[col] &= m_found[row][col];
    }
    }
    if(std::accumulate(row_accum.begin(), row_accum.end(), false, [](bool a, bool b) {return a || b;})) {
        return true;
    }
    if(std::accumulate(col_accum.begin(), col_accum.end(), false, [](bool a, bool b) {return a || b;})) {
        return true;
    }
    return false;
}



void BingoCard::computeScore(unsigned int turn) {
    m_score = 0;
    for (unsigned int row = 0; row < m_found.size(); row++) {
    for (unsigned int col = 0; col < m_found[0].size(); col++) {
        if(!m_found[row][col]) m_score += m_card[row][col];
    }
    }
    m_score *= turn;
}