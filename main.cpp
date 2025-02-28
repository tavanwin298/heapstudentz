#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

// Forward declarations of classes
class Address;
class Date;
class Student;

// Address class definition
class Address {
public:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

    Address(std::string s, std::string c, std::string st, std::string z)
        : street(s), city(c), state(st), zip(z) {}

    void printAddress() const {
        std::cout << street << std::endl;
        std::cout << city << ", " << state << " " << zip << std::endl;
    }
};

// Date class definition
class Date {
public:
    std::string month;
    int day;
    int year;

    Date(std::string m, int d, int y) : month(m), day(d), year(y) {}

    void printDate() const {
        std::cout << month << " " << day << ", " << year << std::endl;
    }
};

// Student class definition
class Student {
public:
    std::string firstName;
    std::string lastName;
    Address* address;
    Date* dob;
    Date* gradDate;
    int creditHours;

    Student(std::string fn, std::string ln, Address* addr, Date* dobDate, Date* grad, int credits)
        : firstName(fn), lastName(ln), address(addr), dob(dobDate), gradDate(grad), creditHours(credits) {}

    ~Student() {
        delete address;
        delete dob;
        delete gradDate;
    }

    void printStudentDetails() const {
        std::cout << firstName << " " << lastName << std::endl;
        address->printAddress();
        std::cout << "DOB: ";
        dob->printDate();
        std::cout << "Grad: ";
        gradDate->printDate();
        std::cout << "Credits: " << creditHours << std::endl;
        std::cout << "____________________________________" << std::endl;
    }

    void printStudentSummary() const {
        std::cout << lastName << ", " << firstName << std::endl;
    }

    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    int getCreditHours() const { return creditHours; }
};

// Function declarations
void loadStudents(std::vector<Student*>& students, const std::string& filename);
void printStudents(const std::vector<Student*>& students);
void showStudentNames(const std::vector<Student*>& students);
void findStudent(const std::vector<Student*>& students, const std::string& lastName);
void delStudents(std::vector<Student*>& students);
void menu();
bool compareByLastName(const Student* a, const Student* b);
bool compareByFirstName(const Student* a, const Student* b);
bool compareByCredits(const Student* a, const Student* b);

// Function to load students from a CSV file
void loadStudents(std::vector<Student*>& students, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string firstName, lastName, street, city, state, zip, dobMonth, gradMonth;
        int dobDay, dobYear, gradDay, gradYear, creditHours;

        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, street, ',');
        std::getline(ss, city, ',');
        std::getline(ss, state, ',');
        std::getline(ss, zip, ',');
        std::getline(ss, dobMonth, ',');
        ss >> dobDay >> std::ws >> dobYear;
        std::getline(ss, gradMonth, ',');
        ss >> gradDay >> std::ws >> gradYear;
        ss >> creditHours;

        Address* addr = new Address(street, city, state, zip);
        Date* dob = new Date(dobMonth, dobDay, dobYear);
        Date* grad = new Date(gradMonth, gradDay, gradYear);
        Student* student = new Student(firstName, lastName, addr, dob, grad, creditHours);
        students.push_back(student);
    }
    file.close();
}

// Function to print all students' details
void printStudents(const std::vector<Student*>& students) {
    for (const auto& student : students) {
        student->printStudentDetails();
    }
}

// Function to show all students' names
void showStudentNames(const std::vector<Student*>& students) {
    for (const auto& student : students) {
        student->printStudentSummary();
    }
}

// Function to find students by last name
void findStudent(const std::vector<Student*>& students, const std::string& lastName) {
    for (const auto& student : students) {
        if (student->getLastName().find(lastName) != std::string::npos) {
            student->printStudentDetails();
        }
    }
}

// Function to delete all students and free memory
void delStudents(std::vector<Student*>& students) {
    for (auto& student : students) {
        delete student;
    }
    students.clear();
}

// Menu function to present options
void menu() {
    std::cout << "0) quit" << std::endl;
    std::cout << "1) print all student names" << std::endl;
    std::cout << "2) print all student data" << std::endl;
    std::cout << "3) find a student" << std::endl;
    std::cout << "Please choose 0-3: ";
}

// Comparison functions for sorting
bool compareByLastName(const Student* a, const Student* b) {
    return a->getLastName() < b->getLastName();
}

bool compareByFirstName(const Student* a, const Student* b) {
    return a->getFirstName() < b->getFirstName();
}

bool compareByCredits(const Student* a, const Student* b) {
    return a->getCreditHours() > b->getCreditHours(); // Descending order
}

int main() {
    std::vector<Student*> students;
    loadStudents(students, "students.csv");

    std::string choice;
    while (true) {
        menu();
        std::getline(std::cin, choice);

        if (choice == "0") {
            break;
        }
        else if (choice == "1") {
            showStudentNames(students);
        }
        else if (choice == "2") {
            printStudents(students);
        }
        else if (choice == "3") {
            std::string lastName;
            std::cout << "Last name of student: ";
            std::getline(std::cin, lastName);
            findStudent(students, lastName);
        }
    }

    delStudents(students);
    return 0;
}
