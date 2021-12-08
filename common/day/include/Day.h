#pragma once
#include <vector>
#include <filesystem>
		
class Day {
    public:
        Day() {};
        void runday(std::vector<std::string> res_files);
    protected:
        virtual std::vector<std::string> run(std::vector<std::string> res_files) = 0;
};