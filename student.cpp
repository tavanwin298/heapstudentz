#include <iostream>
#include <sstream>
#include <string>
#include "student.h"
#include "date.h"
#include "address.h"

// Constructor
Student::Student() : credits(0) {
    // Initialize members to default values
    firstName = "";
    lastName = "";
    address = nullptr;
    birthDate = nullptr;
    gradDate = nullptr;
}

// Destructor
Student::~Student() {
    // Free memory if allocated on the heap
    if (address) {
        delete address;
    }
    if (birthDate) {
        delete birthDate;
    }
    if (gradDate) {
        delete gradDate;
    }
}

// Method to initialize the Student object from a CSV string
void Student::init(const std::string& studentData) {
    std::stringstream ss(studentData);
    std::string token;

    // Parse the data into respective member variables
    std::getline(ss, lastName, ',');
    std::getline(ss, firstName, ',');

    // Address
    std::string street, city, state, zip;
    std::getline(ss, street, ',');
    std::getline(ss, city, ',');
    std::getline(ss, state, ',');
    std::getline(ss, zip, ',');
    address = new Address(street, city, state, zip);

    // Birthdate and Graddate
    std::string birthdate, gradDate;
    std::getline(ss, birthdate, ',');
    std::getline(ss, gradDate, ',');
    this->birthDate = new Date();
    this->birthDate->init(birthdate);

    this->gradDate = new Date();
    this->gradDate->init(gradDate);

    // Credits
    ss >> credits;
}

// Method to print the full student data
void Student::printStudent() const {
    std::cout << firstName << " " << lastName << std::endl;
    address->printAddress();
    std::cout << "DOB: ";
    birthDate->printDate();
    std::cout << "Grad: ";
    gradDate->printDate();
    std::cout << "Credits: " << credits << std::endl;
    std::cout << "____________________________________" << std::endl;
}

// Method to get the student's last name followed by first name
std::string Student::getLastFirst() const {
    return lastName + ", " + firstName;
}

// Method to print only student names (last, first)
void Student::printStudentName() const {
    std::cout << lastName << ", " << firstName << std::endl;
}
