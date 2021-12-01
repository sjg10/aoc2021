#include <iostream>

#include "DayExample.h"

DayExample::DayExample(int value) : example_value(value) {}

void DayExample::run(std::vector<std::string> res_files) {
    std::cout << "Day Example run" << std::endl;
    (void) res_files;
}

int DayExample::getValue() {return example_value;}