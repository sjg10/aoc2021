#include "CucumberHerds.h"

CucumberHerds::CucumberHerds(std::istream &input) {
    char c;
    m_height = 0;
    m_width = 0;
    while(input.get(c)) {
        switch(c) {
            case '>': 
                m_state.push_back(EAST);
                if(m_height == 0) {m_width++;}
                break;
            case 'v': 
                m_state.push_back(SOUTH);
                if(m_height == 0) {m_width++;}
                break;
            case '.': 
                m_state.push_back(EMPTY);
                if(m_height == 0) {m_width++;}
                break;
            case '\n': 
                m_height++;
                break;
        }
    }
}


unsigned int CucumberHerds::getMinSteps() {
    unsigned int steps = 0;
    do { steps++; } while(step());
    return steps;
}


std::ostream& operator<<(std::ostream &o, const CucumberHerds &r) {
    for(unsigned int j = 0; j < r.m_height; j++) {
    for(unsigned int i = 0; i < r.m_width; i++) {
        switch(r.m_state[(j * r.m_width) + i]) {
            case CucumberHerds::State::EMPTY:  o << "."; break;
            case CucumberHerds::State::EAST:  o << ">"; break;
            case CucumberHerds::State::SOUTH:  o << "v"; break;
        }
    }
    o << std::endl;
    }
    return o;
}

/** Move all cucumbers and return true if a cucumber could move */
bool CucumberHerds::step() {
    auto tmp = m_state;
    bool moved = false;
    for(unsigned int j = 0; j < m_height; j++) {
    for(unsigned int i = 0; i < m_width; i++) {
        if(m_state[(j * m_width) + i] == EAST) {
            unsigned int new_loc = (j * m_width) + ((i+1) % m_width);
            if(m_state[new_loc] == EMPTY) {
                tmp[(j * m_width) + i] = EMPTY;
                tmp[new_loc] = EAST;
                moved = true;
            }
        }
    }
    }
    m_state = tmp;
    for(unsigned int j = 0; j < m_height; j++) {
    for(unsigned int i = 0; i < m_width; i++) {
        if(tmp[(j * m_width) + i] == SOUTH) {
            unsigned int new_loc = (((j + 1) % m_height) * m_width) + i;
            if(tmp[new_loc] == EMPTY) {
                m_state[(j * m_width) + i] = EMPTY;
                m_state[new_loc] = SOUTH;
                moved = true;
            }
        }
    }
    }
    return moved;
}