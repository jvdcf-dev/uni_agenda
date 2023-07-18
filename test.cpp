#include "Date.hpp"
#include <iostream>
#include <chrono>
#include <cassert>
using namespace std;

void Date_tests() {
    {Date d = Date();
    time_t t = time(0);
    assert(ctime(&t) == d.str());}
}

int main() {
    Date_tests();
    return 0;
}