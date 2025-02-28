#include "address.h"
#include <iostream>

Address::Address() : street(""), city(""), state(""), zip("") {}

Address::Address(std::string st, std::string ci, std::string stt, std::string z)
    : street(st), city(ci), state(stt), zip(z) {}

void Address::init(std::string st, std::string ci, std::string stt, std::string z) {
    street = st;
    city = ci;
    state = stt;
    zip = z;
}

void Address::printAddress() const {
    std::cout << street << "\n" << city << " " << state << ", " << zip << std::endl;
}
