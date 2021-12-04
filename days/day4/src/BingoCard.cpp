#include <iostream>
#include <sstream>
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
    }
}

unsigned int BingoCard::play(unsigned int turn) {
    if(!m_score) { // i.e. not finished
        for(unsigned int row_idx = 0; row_idx < m_card.size(); row_idx++) {
            auto col_idx = std::find(m_card[row_idx].begin(), m_card[row_idx].end(), turn);
            if(col_idx != m_card[row_idx].end()) {
                m_card[row_idx][col_idx - m_card[row_idx].begin()] = 0;
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
    std::vector<unsigned int> row_accum(m_card.size(), 0);
    std::vector<unsigned int> col_accum(m_card[0].size(), 0);
    
    for (unsigned int row = 0; row < m_card.size(); row++) {
    for (unsigned int col = 0; col < m_card[0].size(); col++) {
        row_accum[row] += m_card[row][col];
        col_accum[col] += m_card[row][col];
    }
    }
    if(std::find(row_accum.begin(), row_accum.end(), 0) != row_accum.end()) {
        return true;
    }
    if(std::find(col_accum.begin(), col_accum.end(), 0) != col_accum.end()) {
        return true;
    }
    return false;
}



void BingoCard::computeScore(unsigned int turn) {
    m_score = 0;
    for (unsigned int row = 0; row < m_card.size(); row++) {
    for (unsigned int col = 0; col < m_card[0].size(); col++) {
        m_score += m_card[row][col];
    }
    }
    m_score *= turn;
}