#include "Image.h"
#include <algorithm>

Image::Image(std::istream &input) {
    char c;
    bool newline = false;
    while(input.get(c)) { //instructions read
        if(c == '.') { m_instructions.push_back(false); newline=false;}
        else if(c == '#') { m_instructions.push_back(true); newline=false;}
        else if(c == '\n') { 
            if (newline) { break; } // double newline -> empty line
            else { newline = true; }
        }
    }
    while(input.get(c)) { // image read
        if(c == '.') {
            m_image.push_back(false); 
            if(m_height == 0) {m_width++;}
        }
        else if(c == '#') {
            m_image.push_back(true); 
            if(m_height == 0) {m_width++;}
        }
        else if(c == '\n') { m_height++;}
    }
}

void Image::enhance() {
    unsigned int old_width = m_width;
    unsigned int old_height = m_height;
    m_width += 2;
    m_height += 2;

    // shortcut for translating loc x,y into flat location;
    unsigned int init = m_surrounding_zeros ? 0 : 0b111111111;
    std::vector<unsigned int> newpixelscommands(m_width * m_height, init);

    // generate reference commands from old image x/y
    for(unsigned int oldx = 0; oldx < old_width ; oldx++) {
    for(unsigned int oldy = 0; oldy < old_height; oldy++) {
        unsigned int x = oldx + 1;
        unsigned int y = oldy + 1;
        if(m_surrounding_zeros &&m_image[loc(oldx,oldy,old_width)]) { // find the ones if surrounding zeros
            newpixelscommands[loc(x-1,y-1)] |= (1 << 0);
            newpixelscommands[loc(x-1,y  )] |= (1 << 1);
            newpixelscommands[loc(x-1,y+1)] |= (1 << 2);

            newpixelscommands[loc(x  ,y-1)] |= (1 << 3);
            newpixelscommands[loc(x  ,y  )] |= (1 << 4);
            newpixelscommands[loc(x  ,y+1)] |= (1 << 5);

            newpixelscommands[loc(x+1,y-1)] |= (1 << 6);
            newpixelscommands[loc(x+1,y  )] |= (1 << 7);
            newpixelscommands[loc(x+1,y+1)] |= (1 << 8);
        }
        else if(!m_surrounding_zeros && !m_image[loc(oldx,oldy,old_width)]) { // mask out the zeros if surrounding ones
            newpixelscommands[loc(x-1,y-1)] &= 0b111111110;
            newpixelscommands[loc(x-1,y  )] &= 0b111111101;
            newpixelscommands[loc(x-1,y+1)] &= 0b111111011;

            newpixelscommands[loc(x  ,y-1)] &= 0b111110111;
            newpixelscommands[loc(x  ,y  )] &= 0b111101111;
            newpixelscommands[loc(x  ,y+1)] &= 0b111011111;

            newpixelscommands[loc(x+1,y-1)] &= 0b110111111;
            newpixelscommands[loc(x+1,y  )] &= 0b101111111;
            newpixelscommands[loc(x+1,y+1)] &= 0b011111111;
        }
    }
    }
    m_image.resize(m_width * m_height);
    for(unsigned int i = 0; i < newpixelscommands.size(); i++) {
        m_image[i] = m_instructions.at(newpixelscommands.at(i));
    }
    // update if surrounded by zeros
    if (m_surrounding_zeros && m_instructions[0]) {m_surrounding_zeros = false;}
    else if (!m_surrounding_zeros && !m_instructions[0b111111111]) {m_surrounding_zeros = true;}
}

unsigned int Image::pixelCount() {
    if(!m_surrounding_zeros) {throw std::runtime_error("Could not get pixel count: infinite\n");}
    return std::count(m_image.begin(), m_image.end(), true);
}

std::ostream& operator<<(std::ostream& os, const Image& img)
{
    for (unsigned int x = 0; x < img.m_height; x++ ) {
        for (unsigned int y = 0; y < img.m_width; y++ ) {
            os << (img.m_image[img.loc(x,y)] ? "#" : ".");
        }
        os << "\n";
    }
    return os;
}