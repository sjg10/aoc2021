#include "Packet.h"
#include <algorithm>
#include <numeric>

/** Consume bits from in from m_bits_processed offset and increment the offset */
unsigned long int Packet::consume(const std::vector<bool> &in, unsigned int bits) { 
    auto ret = std::accumulate(in.begin() + m_bits_processed, in.begin() + m_bits_processed + bits, 0UL, 
        [](unsigned int a, auto b) { return (a << 1) | b; }
    );
    m_bits_processed += bits;
    return ret;
}

Packet::Packet(const std::vector<bool> &in, unsigned int start_idx) {
    m_bits_processed = start_idx;
    m_version = consume(in, 3);
    m_type = consume(in, 3);

    if(m_type == 4) { // no subpackets
        bool cont_char = true;
        m_contents = 0;
        while (cont_char) {
            cont_char = consume(in, 1);
            m_contents <<= 4;
            m_contents |= consume(in, 4);
        }
    }
    else { // get subpackets
        m_subpacket_count_type = consume(in,1);
        if(m_subpacket_count_type) {
            m_subpacket_count = consume(in,11);
            for(unsigned int i =0; i < m_subpacket_count; i++) {
                m_subpackets.push_back(std::make_unique<Packet>(in, m_bits_processed));
                m_bits_processed = m_subpackets.back()->m_bits_processed;
            }
        }
        else {
            m_subpacket_count =  consume(in,15);
            auto cur_bits = m_bits_processed;
            while(m_bits_processed - cur_bits < m_subpacket_count) {
                m_subpackets.push_back(std::make_unique<Packet>(in, m_bits_processed));
                m_bits_processed = m_subpackets.back()->m_bits_processed;
            }
        }
    }
}

unsigned int Packet::getTotalVersionScore() const {
    unsigned int out = getVersion();
    for(auto const &p: m_subpackets) { out += p->getTotalVersionScore();};
    return out;
}

unsigned long int Packet::getContents() const {
    unsigned long int ret  = 0;
    switch(m_type) {
        case 0: // sum
            ret = 0;
            for(auto const &sp: m_subpackets) {
                ret += sp->getContents();
            }
            break;
        
        case 1: // product
            ret = 1;
            for(auto const &sp: m_subpackets) {
                ret *= sp->getContents();
            }
            break;
        
        case 2: // min
            ret = std::numeric_limits<unsigned long long int>::max();
            for(auto const &sp: m_subpackets) {
                auto tmp = sp->getContents();
                if(tmp < ret) { ret = tmp;}
            }
            break;

        case 3: // max
            ret = std::numeric_limits<unsigned long long int>::min();
            for(auto const &sp: m_subpackets) {
                auto tmp = sp->getContents();
                if(tmp > ret) { ret = tmp;}
            }
            break;
        case 4: // plain
            ret = m_contents;
            break;
        case 5: // gt
            ret = m_subpackets[0]->getContents() > m_subpackets[1]->getContents() ? 1 : 0;
            break;
        case 6: // lt
            ret = m_subpackets[0]->getContents() < m_subpackets[1]->getContents() ? 1 : 0;
            break;
        case 7: // eq
            ret = m_subpackets[0]->getContents() == m_subpackets[1]->getContents() ? 1 : 0;
            break;
        default:
            throw std::runtime_error("Unknown type ");
            break;
    }
    return ret;
}
