#include "Date.hpp"
#include <iostream>
#include <chrono>
#include <cassert>
using namespace std;

void Date_tests() {
    {Date d = Date();
    time_t t = time(0);
    assert(ctime(&t) == d.str());}

    {Date d = Date(2023, 7, 19, 18, 18, 18);
    assert(d.str() == "Wed Jul 19 18:18:18 2023\n");}

    try {
        {Date d = Date(1753, 0, 1, 48, 0, 0);
        cout << d.str();}
    } catch(char const* e) {}

    {Date d1 = Date(1900, 1, 1, 0, 0, 0);
    Date d2 = Date(1900, 1, 1, 1, 1, 1);
    assert(d2 - d1 == 3661s);}

    {Date d = Date(2020, 9, 20, 21, 59, 1);
    auto ymd = d.ymd();
    assert(ymd.day() == std::chrono::day(20));
    assert(ymd.month() == std::chrono::month(9));
    assert(ymd.year() == std::chrono::year(2020));}

    {Date d = Date(1990, 1, 1, 15, 23, 46);
    auto hms = d.hms();
    assert(hms.seconds() == std::chrono::seconds(46));
    assert(hms.minutes() == std::chrono::minutes(23));
    assert(hms.hours() == std::chrono::hours(15));}
}


void Temporary() {
}

int main() {
    Date_tests();
    Temporary();
    return 0;
}