#include <iostream>
#include "address.h"
#include "date.h"

void testAddress();
void testDate();

int main() {
    std::cout << "Hello!" << std::endl;
    testAddress();
    testDate();
    return 0;
}

void testAddress() {
    Address a;
    a.init("123 W Main St", "Muncie", "IN", "47303");
    a.printAddress();
}

void testDate() {
    Date d;
    d.init("01/27/1997");
    d.printDate();
}
