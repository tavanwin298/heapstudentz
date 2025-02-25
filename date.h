#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int day, month, year;
    std::string monthNames[12] = { "January", "February", "March", "April", "May", "June",
                                   "July", "August", "September", "October", "November", "December" };

public:
    Date();
    Date(std::string dateStr);
    void init(std::string dateStr);
    void printDate() const;
};

#endif // DATE_H
