#pragma once
#include <vector>
#include <filesystem>
		
class Day {
    public:
        Day() {};
        virtual void run(std::vector<std::filesystem::path> res_files) = 0;
};