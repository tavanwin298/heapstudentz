#ifndef STUDENT_H
#define STUDENT_H

#include "address.h"
#include "date.h"
#include <string>

class Student {
private:
    std::string firstName, lastName;
    Address address;
    Date birthDate, gradDate;
    int creditHours;

public:
    Student();
    void init(std::string studentData);
    void printStudent() const;
    std::string getLastFirst() const;
};

#endif // STUDENT_H
