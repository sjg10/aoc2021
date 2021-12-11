#include "OctoMap.h"

OctoMap::OctoMap(std::istream &input) {
    std::vector<unsigned int> cur = {};
    char c;
    while(input.get(c)) {
        if(c == '\n') {
            m_map.push_back(cur);
            cur = {};
        }
        else {
            cur.push_back(c - '0');
        }
    }
}

bool OctoMap::takeTurn(void) {
    for (unsigned int i = 0; i < HEIGHT; i++) {
    for (unsigned int j = 0; j < WIDTH; j++) {
        checkFlash(i,j);
    }
    }
    unsigned int flashed = 0;
    for (unsigned int i = 0; i < HEIGHT; i++) {
    for (unsigned int j = 0; j < WIDTH; j++) {
        if(m_map[i][j] >= 10) {
            m_map[i][j] = 0;
            flashed++;
        }
    }
    }
    return (flashed == (HEIGHT * WIDTH));
}

unsigned int OctoMap::getFlashes(void) {return m_flashes;}

/** Increment the map at (i,j), increment flash counter if flashed, increment and check neighbours too */
void OctoMap::checkFlash(unsigned int i, unsigned int j) {
    m_map[i][j]++;
    if(m_map[i][j] == 10) {
        m_flashes++;
        if (i < HEIGHT - 1) {
            checkFlash(i + 1, j);
            if (j < WIDTH - 1) {
                checkFlash(i + 1, j + 1);
            }
            if (j > 0) {
                checkFlash(i + 1, j - 1);
            }
        }
        if (i > 0) {
            checkFlash(i - 1, j);
            if (j < WIDTH - 1) {
                checkFlash(i - 1, j + 1);
            }
            if (j > 0) {
                checkFlash(i - 1, j - 1);
            }
        }
        if (j < WIDTH - 1) {
            checkFlash(i, j + 1);
        }
        if (j > 0) {
            checkFlash(i, j - 1);
        }
    }
}