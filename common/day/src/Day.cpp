#include <chrono>
#include <iostream>
#include "Day.h"

void Day::runday(std::vector<std::string> res_files) {

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = std::chrono::high_resolution_clock::now();
    run(res_files);
    auto t2 = std::chrono::high_resolution_clock::now();

    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);

    /* Getting number of milliseconds as a double. */
    //duration<double, std::milli> ms_double = t2 - t1;

    //std::cout << ms_int.count() << "ms\n";
    std::cout << "Elapsed time " << ms_int.count() << "ms" << std::endl << std::endl;
}
