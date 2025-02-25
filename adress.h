#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
private:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

public:
    Address();
    Address(std::string st, std::string ci, std::string stt, std::string z);
    void init(std::string st, std::string ci, std::string stt, std::string z);
    void printAddress() const;
};

#endif // ADDRESS_H
