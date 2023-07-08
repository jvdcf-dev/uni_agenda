#include "Date.hpp"
#include <iostream>
#include <cassert>
using namespace std;

void Date_tests() {
    {Date d = Date();
    cout << d.str() << '\n';} // TODO: Manual test

    {Date d = Date(0);
    assert(d.str() == "Thu Jan  1 01:00:00 1970");
    }
}

int main() {
    Date_tests();
    return 0;
}