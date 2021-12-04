#pragma once
#include <string>

/** A day2 submarine that can be moved with an instruction list */
class Submarine  {
    public:
        Submarine() {};
        /** Move the submarine according to an instruction intepreted basically */
        void moveBasic(std::string move_command);
        /** Move the submarine according to an instruction intepreted as an aim command */
        void moveAimed(std::string move_command);
        /** Get the representation of the submarine location */
        int getLocation();
    private:
        int x = 0;
        int y = 0;
        int aim = 0;
};