#include <gtest/gtest.h>
#include "Image.h"


TEST(Day20, Main) {
    std::stringstream in;
    in << "..#.#..#####.#.#.#.###.##.....###.##.#..###.####..#####..#....#..#..##..##\n";
    in << "#..######.###...####..#..#####..##..#.#####...##.#.#..#.##..#.#......#.###\n";
    in << ".######.###.####...#.##.##..#..#..#####.....#.#....###..#.##......#.....#.\n";
    in << ".#..#..##..#...##.######.####.####.#.#...#.......#..#.#.#...####.##.#.....\n";
    in << ".#..#...##.#.##..#...##.#.##..###.#......#.#.......#.#.#.####.###.##...#..\n";
    in << "...####.#..#..#.##.#....##..#.####....##...##..#...#......#.#.......#.....\n";
    in << "..##..####..#...#.#.#...##..#.#..###..#####........#..####......#..#\n";
    in << "\n";
    in << "#..#.\n";
    in << "#....\n";
    in << "##..#\n";
    in << "..#..\n";
    in << "..###\n";
    auto image = Image(in);
    std::stringstream out;
    std::stringstream out_cmp;
    out << "#..#.\n";
    out << "#....\n";
    out << "##..#\n";
    out << "..#..\n";
    out << "..###\n";
    out_cmp << image;
    EXPECT_EQ(out_cmp.str(), out.str());

    image.enhance();

    out_cmp.str(""); out.str("");
    out << ".##.##.\n";
    out << "#..#.#.\n";
    out << "##.#..#\n";
    out << "####..#\n";
    out << ".#..##.\n";
    out << "..##..#\n";
    out << "...#.#.\n";
    out_cmp << image;
    EXPECT_EQ(out_cmp.str(), out.str());
    
    image.enhance();

    out_cmp.str(""); out.str("");
    out << ".......#.\n";
    out << ".#..#.#..\n";
    out << "#.#...###\n";
    out << "#...##.#.\n";
    out << "#.....#.#\n";
    out << ".#.#####.\n";
    out << "..#.#####\n";
    out << "...##.##.\n";
    out << "....###..\n";    
    out_cmp << image;
    EXPECT_EQ(out_cmp.str(), out.str());
    EXPECT_EQ(image.pixelCount(), 35);

    for (int i =2; i < 50; i++) {
        image.enhance();
    }
    EXPECT_EQ(image.pixelCount(), 3351);

}
