#pragma once
#include <iostream>
#include <string>

/** A SnailFish Number */
class SFNumber {
    public:
        /** Create a (reduced) snailfish number from the string representation */
        SFNumber(std::string input);
        /** Right add n to this snailfish number and reduce */
        void radd(const SFNumber &n);
        /* Get the magnitude of this snailfish number */
        unsigned int magnitude();
        /** Produce the strrep of dt to the os stream */
        friend std::ostream& operator<<(std::ostream& os, const SFNumber& dt);
    private:
        void reduce();
        static const int OPEN_PAIR;
        static const int CLOSE_PAIR;
        static const int COMMA;
        std::vector<int> m_array;
};