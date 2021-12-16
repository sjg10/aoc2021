#pragma once
#include <iostream>
#include <vector>
#include <memory>

class Packet {
    public:
        /** Create a packet from the given bit array, parsing from the given start index */
        Packet(const std::vector<bool> &in, unsigned int start_idx);
        /** Get the verion of the top packet */
        unsigned int getVersion() const { return m_version; };
        /** Get the type of the top packet */
        unsigned int getType() const { return m_type; };
        /** Get the parsed constents of the packet */
        unsigned long int getContents() const;
        /* Get the total version of all packets, summed */
        unsigned int getTotalVersionScore() const;
    private:
        unsigned long int consume(const std::vector<bool> &in, unsigned int bits);

        std::vector<std::unique_ptr<Packet>> m_subpackets;
        unsigned int m_version;
        unsigned int m_type;
        unsigned int m_subpacket_count_type;
        unsigned int m_subpacket_count; // packets if m_subpacket_count_type = 1, bits o/w
        unsigned long int m_contents; // only set if type == 4
        unsigned int m_bits_processed; // how many bits consumed by this packet
};