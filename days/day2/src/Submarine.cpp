#include <iostream>
#include <fstream>
#include "Submarine.h"


void Submarine::moveBasic(std::string move_command) {
    auto space_idx = move_command.find(" ");
    int quantity = std::stoi(move_command.substr(space_idx + 1));
    std::string direction = move_command.substr(0, space_idx);
    if (direction == "forward") {x += quantity;}
    else if (direction == "down") {y += quantity;}
    else if (direction == "up") {y -= quantity;}
    else {throw std::runtime_error("unknown direction from string "+ move_command);}
}

void Submarine::moveAimed(std::string move_command) {
    auto space_idx = move_command.find(" ");
    int quantity = std::stoi(move_command.substr(space_idx + 1));
    std::string direction = move_command.substr(0, space_idx);
    if (direction == "forward") {x += quantity; y+= aim * quantity;}
    else if (direction == "down") {aim += quantity;}
    else if (direction == "up") {aim -= quantity;}
    else {throw std::runtime_error("unknown direction from string "+ move_command);}
}

int Submarine::getLocation(){
    return x*y;
}