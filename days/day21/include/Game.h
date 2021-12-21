#pragma once
#include <iostream>
#include <array>
#include <map>

/** Stores an game and plays it */
class Game {
    public:
        /** Create an game at its initial state */
        Game(unsigned int p1_start, unsigned int p2_start) : 
            m_init_p1loc(p1_start),m_init_p2loc(p2_start)  {};
        /** Play the determinstic game and return the winning calculated score */
        unsigned int playGame() const;
        /** Play the quantum game and return the play1wins, play2wins pair */
        std::pair<unsigned long int, unsigned long int>  playQuantumGame() const;
    private:
        const unsigned int m_init_p1loc;
        const unsigned int m_init_p2loc;
        struct GameState { // Stores a current game state
            unsigned int p1loc;
            unsigned int p2loc;
            unsigned int p1score = 0;
            unsigned int p2score = 0;
            bool operator<(const GameState &o)  const { /** For use in map */
                return (p1score < o.p1score)  || 
                    ((p1score == o.p1score) && (p2score < o.p2score)) ||
                    ((p1score == o.p1score) && (p2score == o.p2score) && (p1loc < o.p1loc)) ||
                    ((p1score == o.p1score) && (p2score == o.p2score) && (p1loc == o.p1loc) && (p2loc < o.p2loc));
            }
            void applyRoll(unsigned int player, unsigned int roll) { /** Move the player */
                if(player == 1) {
                    p1loc = (((p1loc + roll ) - 1) % 10) + 1;
                    p1score = p1score + p1loc;
                }
                else {
                    p2loc = (((p2loc + roll ) - 1) % 10) + 1;
                    p2score = p2score + p2loc;
                } 
            }
        };

        // The determinate dice sum rolls (repeating)
        static constexpr std::array<int, 10> m_dice_roll = {6, 5, 4, 3, 2, 1, 10, 9, 8, 7};
        // The quantum dice roll sums with their splits
        static constexpr std::array<std::pair<unsigned int, unsigned int>, 7> m_possible_quantum_rolls = {
            std::make_pair(3,1),
            std::make_pair(4,3),
            std::make_pair(5,6),
            std::make_pair(6,7),
            std::make_pair(7,6),
            std::make_pair(8,3),
            std::make_pair(9,1)
        };

};

