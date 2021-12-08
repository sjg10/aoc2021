#include <chrono>
#include <iostream>
#include "Day.h"

void Day::runday(std::vector<std::string> res_files) {
    auto t1 = std::chrono::high_resolution_clock::now();
    auto res = run(res_files);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

    for(unsigned int i = 0; i < res.size(); i++) {
        std::cout << "Part " << i + 1 << ": " << res[i] << std::endl;
    }
    std::cout << "Elapsed time " << ms_int.count() << "ms" << std::endl << std::endl;
}
