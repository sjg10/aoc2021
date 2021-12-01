#pragma once
#include <vector>
#include <filesystem>
		
class Day {
    public:
        Day() {};
        virtual void run(std::vector<std::string> res_files) = 0;
};