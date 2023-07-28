#include "Date.hpp"
#include "Time.hpp"
#include "Assessment.hpp"
#include "Task.hpp"
#include "Summary.hpp"
#include "Subject.hpp"
#include "Semester.hpp"
#include "Course.hpp"

#include <iostream>
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
    } catch(const char* e) {}

    {Date d1 = Date(1900, 1, 1, 0, 0, 0);
    Date d2 = Date(1900, 1, 1, 1, 1, 1);
    assert(d2 - d1 == 3661s);}

    {Date d = Date(2020, 9, 20, 21, 59, 1);
    auto ymd = d.get_ymd();
    assert(ymd.day() == std::chrono::day(20));
    assert(ymd.month() == std::chrono::month(9));
    assert(ymd.year() == std::chrono::year(2020));}

    {Date d = Date(1990, 1, 1, 15, 23, 46);
    auto hms = d.get_hms();
    assert(hms.seconds() == std::chrono::seconds(46));
    assert(hms.minutes() == std::chrono::minutes(23));
    assert(hms.hours() == std::chrono::hours(15));}

    {Date d = Date();
    d.set_ymd(2022, 12, 26);
    d.set_hms(10, 5, 23);
    assert(d.str() == "Mon Dec 26 10:05:23 2022\n");}

    {Date d = Date(2022, 12, 25, 0, 0, 0);
    assert(d.get_weekday() == 0);}
}


void time_tests() {}


/* void assessment_tests() {
    {Assessment a = Assessment();
    assert(a.get_name() == "N/A");
    assert(a.get_weight() == 0);
    assert(a.get_date().year() == std::chrono::year(1900));
    assert(a.get_date().month() == std::chrono::month(1));
    assert(a.get_date().day() == std::chrono::day(1));
    assert(a.get_grade() == 0);}

    {Assessment a = Assessment("Test", 0.5, 2020, 9, 20, 15.2);
    assert(a.get_name() == "Test");
    assert(a.get_weight() == 0.5);
    assert(a.get_date().year() == std::chrono::year(2020));
    assert(a.get_date().month() == std::chrono::month(9));
    assert(a.get_date().day() == std::chrono::day(20));
    assert(a.get_grade() == 15.2);}

    {Assessment a = Assessment("Another test", 0.9, 2020, 11, 23, 18.4);
    a.set_name("Just a test");
    a.set_weight(0.4);
    a.set_date(2022, 12, 26);
    a.set_grade(17.5);
    assert(a.get_name() == "Just a test");
    assert(a.get_weight() == 0.4);
    assert(a.get_date().year() == std::chrono::year(2022));
    assert(a.get_date().month() == std::chrono::month(12));
    assert(a.get_date().day() == std::chrono::day(26));
    assert(a.get_grade() == 17.5);}

    try {
        {Assessment a = Assessment();
        a.set_grade(-13.4);}
    } catch(const char* e) {}

    try {
        {Assessment a = Assessment();
        a.set_weight(1.2);}
    } catch(const char* e) {}

    try {
        {Assessment a = Assessment();
        a.set_grade(23.25);}
    } catch(const char* e) {}

    try {
        {Assessment a = Assessment();
        a.set_weight(-0.1);}
    } catch(const char* e) {}
} */


void task_tests() {}
void summary_tests() {}
void subject_tests() {}
void semester_tests() {}
void course_tests() {}

void Temporary() {}


int main() {
    Date_tests();
    time_tests();
    /* assessment_tests(); */
    task_tests();
    summary_tests();
    subject_tests();
    semester_tests();
    course_tests();
    Temporary();
    return 0;
}