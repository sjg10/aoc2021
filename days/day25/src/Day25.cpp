#include <iostream>
#include "Day25.h"
#include "CucumberHerds.h"


std::vector<std::string> Day25::run(std::ifstream &input) {
    std::vector<std::string> out;
    out.push_back(std::to_string(getSteps(input)));
    out.push_back("MERRY CHRISTMAS");
    return out;
}


unsigned int Day25::getSteps(std::istream &input) {
    auto b = CucumberHerds(input);
    return b.getMinSteps();
}
