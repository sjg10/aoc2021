#include <gtest/gtest.h>
#include "Day16.h"
#include "Packet.h"

TEST(Day16Test, Packet1) {
    std::stringstream in;
    in << "D2FE28";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getVersion(), 6);
    EXPECT_EQ(p.getType(), 4);
    EXPECT_EQ(p.getContents(), 2021);
}
TEST(Day16Test, Packet2) {
    std::stringstream in;
    in << "38006F45291200";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getVersion(), 1);
    EXPECT_EQ(p.getType(), 6);
}

TEST(Day16Test, Packet3) {
    std::stringstream in;
    in << "EE00D40C823060";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getVersion(), 7);
    EXPECT_EQ(p.getType(), 3);
}


TEST(Day16Test, Packet4) {
    std::stringstream in;
    in << "8A004A801A8002F478";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getTotalVersionScore(), 16);
}

TEST(Day16Test, Packet5) {
    std::stringstream in;
    in << "620080001611562C8802118E34";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getTotalVersionScore(), 12);
}


TEST(Day16Test, Packet6) {
    std::stringstream in;
    in << "C0015000016115A2E0802F182340";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getTotalVersionScore(), 23);
}

TEST(Day16Test, Packet7) {
    std::stringstream in;
    in << "A0016C880162017C3686B18A3D4780";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getTotalVersionScore(), 31);
}


TEST(Day16Test, Packet8) {
    std::stringstream in;
    in << "C200B40A82";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getContents(), 3);
}


TEST(Day16Test, Packet9) {
    std::stringstream in;
    in << "04005AC33890";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getContents(), 54);
}


TEST(Day16Test, Packet10) {
    std::stringstream in;
    in << "880086C3E88112";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getContents(), 7);
}

TEST(Day16Test, Packet11) {
    std::stringstream in;
    in << "CE00C43D881120";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getContents(), 9);
    EXPECT_EQ(p.getContents(), 9);
}

TEST(Day16Test, Packet12) {
    std::stringstream in;
    in << "D8005AC2A8F0";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getContents(), 1);
}

TEST(Day16Test, Packet13) {
    std::stringstream in;
    in << "F600BC2D8F";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getContents(), 0);
}

TEST(Day16Test, Packet14) {
    std::stringstream in;
    in << "9C005AC2F8F0";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getContents(), 0);
}

TEST(Day16Test, Packet15) {
    std::stringstream in;
    in << "9C0141080250320F1802104A08";
    auto parsed = Day16::parseInput(in);
    auto p = Packet(parsed, 0);
    EXPECT_EQ(p.getContents(), 1);
}