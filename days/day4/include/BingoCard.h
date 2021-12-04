#pragma once
#include <vector>

class BingoCard {
    public:
        BingoCard(std::vector<std::string> cards);
        /** Play a turn. Returns the score if this was the winning turn. 0 if you didnt win or already won */
        unsigned int play(unsigned int turn);
    private:
        bool checkWin();
        void computeScore(unsigned int turn);
        std::vector<std::vector<unsigned int>> m_card;
        unsigned int m_score = 0; // non zero indicates terminated
};