#include "Date.hpp"
#include <iostream>
#include <cassert>
using namespace std;

void Date_tests() {
    {Date d = Date();
    cout << "Manual test | Local Time: "<< d.str() << '\n';} // TODO: Manual test

    {Date d = Date(0);
    assert(d.str() == "Thu Jan  1 00:00:00 1970\n");
    }
}

int main() {
    Date_tests();
    return 0;
}