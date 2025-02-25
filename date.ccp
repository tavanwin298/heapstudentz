#include "date.h"
#include <iostream>
#include <sstream>

Date::Date() : day(1), month(1), year(2000) {}

Date::Date(std::string dateStr) {
    init(dateStr);
}

void Date::init(std::string dateStr) {
    std::stringstream ss(dateStr);
    std::string temp;
    getline(ss, temp, '/'); month = std::stoi(temp);
    getline(ss, temp, '/'); day = std::stoi(temp);
    getline(ss, temp); year = std::stoi(temp);
}

void Date::printDate() const {
    std::cout << monthNames[month - 1] << " " << day << ", " << year << std::endl;
}
