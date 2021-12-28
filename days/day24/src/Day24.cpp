#include <iostream>
#include <array>
#include "Day24.h"
#include <assert.h>

std::vector<std::string> Day24::run(std::ifstream &input) {
    std::vector<std::string> out;
    auto res = findModel(input);
    out.push_back(std::to_string(res.first));
    out.push_back(std::to_string(res.second));
    return out;
}


std::pair<unsigned long int, unsigned long int> Day24::findModel(std::istream &input) {
    /* Assuming the input format as checked below we can unravel the program.
    * Unravelling the input we obtain after each reading of input in to w:
    * x = ((z % 26) + xin) != w)
    * z = (z / zin) * (25*x + 1) + x(w + yin)
    * 
    * Note too that (ensured by asserts below): 
    * 1) 1 <= yin <= 15
    * 2) zin == 1 or zin == 26
    * 3) When zin == 26 : xin < 10
    * 4) When zin == 1  : xin >= 10
    * 5) There are 7 steps s.t. zin == 1, and 7 zin ==26.
    * 6) Every step where zin == 26 there was a coresponding previous zin==1 step
    * 
    * 
    * Using fact 2 there are three cases possible with the inputs:
    * Case 1:
    * zin == 1 (and xin >= 10)
    * => x = 1, so znew = (26 * zold) + (w + yin)
    * Note 2 < w + yin < 26 (b/c fact 1)
    * 
    * Case 2a:
    * zin == 26 (and xin < 0), where ((z % 26) + xin) != w)
    * => x = 1, so znew = (26 * (zold/26) ) + (w + yin)
    * Note 2 < w + yin < 26 (b/c fact 1)
    * 
    * Case 2b:
    * zin == 26 (and xin < 0), where ((z % 26) + xin) == w)
    * => x = 1, so znew = zold / 26
    * 
    * i.e. if we write z in base 26:
    * case 1 shifts z left and sets lowest digit to (w+yin)
    * case 2a shifts replaces lowest digit with (w+yin)
    * case 2b shifts right.
    * 
    * As we need z to be 0 at the end we need to shift right as much as we shift left
    * and case 1 happens 7 times, and case2a, case2b combine to occur 7 times
    * hence we cannot allow case 2a to occur.
    * 
    * So whenever zin = 26 we need zold % 26 == w - xin
    * zold % 26 is the lowest base 26 digit of zold.
    * If the previous step was case 1, this zold % 26 is that previous w + yin (consider that case 1 "paired")
    * If that previous step wasnt case 1, step backwards through paired case 1's to the first unpaired.
    * That yin+w is zold %26. Fact 6  ensures there was a previous pairing.
    * This gives us the constraint that for every case 2b (step i) and its paired case 1 (step j) (note j<i)
    * w_i - xin_i == yin_j + w_j hence w_j = w_i - (xin_i + yin_j)
    * 
    */
    std::string read_line;
    std::vector<int> addx;
    std::vector<int> divz;
    std::vector<int> addy;
    //read in data and verify assumed facts
    for(int i = 0; i < 14; i++) {
        std::getline(input,read_line); assert(read_line == "inp w");
        std::getline(input,read_line); assert(read_line == "mul x 0");
        std::getline(input,read_line); assert(read_line == "add x z");
        std::getline(input,read_line); assert(read_line == "mod x 26"); 

        std::getline(input,read_line); 
        assert(read_line.substr(0, 6) == "div z ");
        divz.push_back(std::stoi(read_line.substr(6)));
        
        std::getline(input,read_line); 
        assert(read_line.substr(0, 6) == "add x ");
        addx.push_back(std::stoi(read_line.substr(6)));
        assert((divz.back() == 26 && addx.back() < 0) || (divz.back() == 1 && addx.back() > 0)); // assert fact 2,3,4
        assert(std::count(divz.begin(), divz.end(), 1) >=  std::count(divz.begin(), divz.end(), 26)); // assert 6
        
        std::getline(input,read_line); assert(read_line == "eql x w");
        std::getline(input,read_line); assert(read_line == "eql x 0");
        std::getline(input,read_line); assert(read_line == "mul y 0");
        std::getline(input,read_line); assert(read_line == "add y 25");
        std::getline(input,read_line); assert(read_line == "mul y x");
        std::getline(input,read_line); assert(read_line == "add y 1");
        std::getline(input,read_line); assert(read_line == "mul z y");
        std::getline(input,read_line); assert(read_line == "mul y 0");
        std::getline(input,read_line); assert(read_line == "add y w");
        
        std::getline(input,read_line); 
        assert(read_line.substr(0, 6) == "add y ");
        addy.push_back(std::stoi(read_line.substr(6)));
        assert(addy.back() <= 15 && addy.back() >= 1); // assert fact 1

        std::getline(input,read_line); assert(read_line == "mul y x");
        std::getline(input,read_line); assert(read_line == "add z y");

    }
    assert(!std::getline(input,read_line));
    assert(std::count(divz.begin(), divz.end(), 1) == 7); //assert 5
    assert(std::count(divz.begin(), divz.end(), 26) == 7);//assert 5

    // find constraints and compute
    std::vector<int> caseones;
    std::array<int, 14> largest;
    std::array<int, 14> smallest;
    for(unsigned int i = 0; i < divz.size(); i++) {
        if(divz[i] == 1) {
            caseones.push_back(i);
        }
        else {
            int j = caseones.back();
            caseones.pop_back();
            // Remembering that w_j = w_i - (xin_i + yin_j) for [j<i]
            if(addx[i] + addy[j] >= 0 ) {
                largest[i] = 9;
                largest[j] = 9 - (addx[i] + addy[j]);
                smallest[j] = 1;
                smallest[i] = 1 + (addx[i] + addy[j]);
            }
            else {
                largest[j] = 9;
                largest[i] = 9 + (addx[i] + addy[j]);
                smallest[i] = 1;
                smallest[j] = 1 - (addx[i] + addy[j]);
            }
            //TODO:: smallest for part 2
        }
    }
    unsigned long int part1 = 0;
    unsigned long int part2 = 0;
    for(unsigned int i = 0; i < 14; i++) {
        part1 *= 10;
        part1 += largest[i];
        part2 *= 10;
        part2 += smallest[i];
    }
    std::cout << std::endl;
    return {part1,part2};
}
