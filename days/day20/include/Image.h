#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>

/** Stores an image and its enhancement instructions */
class Image {
    public:
        /** Create an image from an input stream */
        Image(std::istream &input);
        /** Apply the enhancement algorithm once */
        void enhance();
        /** Get the number of lit pixels. Throws if infinite */
        unsigned int pixelCount();
        friend std::ostream& operator<<(std::ostream& os, const Image& img); 
    private:
        /** Get the flattened x,y coord using image width */
        unsigned int loc(unsigned int x, unsigned int y) const {return (x * m_width) + y;}
        /** Get the flattened x,y coord using given width */
        unsigned int loc(unsigned int x, unsigned int y, unsigned int width) const {return (x * width) + y;}
        std::vector<bool> m_instructions;
        std::vector<bool> m_image;
        unsigned int m_width = 0;
        unsigned int m_height = 0;
        bool m_surrounding_zeros = true;
};