#include "Game.h"

unsigned int Game::playGame() const {
    GameState state{.p1loc = m_init_p1loc,.p2loc = m_init_p2loc};
    auto res = 0;
    unsigned int rolls = 0;
    while(res == 0) {
        // P1 turn
        state.applyRoll(1, m_dice_roll.at(rolls++ % 10));
        if(state.p1score >= 1000) {
            res = (rolls * 3) * state.p2score;
            break;
        }
        // P2 turn
        state.applyRoll(2, m_dice_roll.at(rolls++ % 10));
        if(state.p2score >= 1000) {
            res = (rolls * 3) * state.p1score;
            break;
        }
    }
    return res;
}



std::pair<unsigned long int, unsigned long int> Game::playQuantumGame() const {
    std::map<GameState, unsigned long int> global_state;
    unsigned long int p1_wins = 0;
    unsigned long int p2_wins = 0;
    global_state[GameState{.p1loc = m_init_p1loc,.p2loc = m_init_p2loc}] = 1;
    while(!global_state.empty()) {
        // Player 1's take a turn
        std::map<GameState, unsigned long int> new_global_state_1;
        for(auto const& [p1roll, instances] : m_possible_quantum_rolls) {
            for(auto const& [g,i]: global_state) {
                unsigned long int new_instances = instances * i;
                GameState newg = g;
                newg.applyRoll(1,p1roll);
                if (newg.p1score >= 21) {p1_wins+=new_instances;}
                else { new_global_state_1[newg] += new_instances; }
            }
        }
        // Player 2's take a turn
        std::map<GameState, unsigned long int> new_global_state_2;
        for(auto const& [p2roll, instances] : m_possible_quantum_rolls) {
            for(auto const& [g,i]: new_global_state_1) {
                unsigned long int new_instances = instances * i;
                GameState newg = g;
                newg.applyRoll(2,p2roll);
                if (newg.p2score >= 21) {p2_wins+=new_instances;}
                else { new_global_state_2[newg] += new_instances; }
            }
        }
        global_state = new_global_state_2;
    }
    return {p1_wins, p2_wins};
}