#include "include/Date.hpp"
#include "include/Time.hpp"
#include "include/Assessment.hpp"
#include "include/Task.hpp"
#include "include/Summary.hpp"
#include "include/Subject.hpp"
#include "include/Semester.hpp"
#include "include/Course.hpp"

#include <iostream>    
#include <cassert>
#include <unistd.h>     // sleep() for Unix machines (use <windows.h> for Windows machines)
#include <stdexcept>
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
    } catch(const std::exception& e) {}

    {Date d1 = Date(1900, 1, 1, 0, 0, 0);
    Date d2 = Date(1900, 1, 1, 1, 1, 1);
    assert(d2 - d1 == 3661s);}

    {Date d1 = Date(1900, 1, 1, 0, 0, 0);
    Date d2 = Date(1900, 1, 1, 1, 1, 1);
    assert((d1 < d2) == true);
    assert((d1 > d2) == false);
    assert((d1 <= d2) == true);
    assert((d1 >= d2) == false);}

    {Date d1 = Date(2023, 3, 32, 0, 0, 0);
    Date d2 = Date(2023, 3, 32, 0, 0, 0);
    assert((d1 < d2) == false);
    assert((d1 > d2) == false);
    assert((d1 <= d2) == true);
    assert((d1 >= d2) == true);}

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


void time_tests() {
    {Time t = Time();
    assert(t.get_time() == 0s);
    assert(t.get_hms().hours() == 0h);
    assert(t.get_hms().minutes() == 0min);
    assert(t.get_hms().seconds() == 0s);
    assert(t.is_running() == false);}

    {Time t = Time(1, 2, 3);
    assert(t.get_time() == 3723s);
    assert(t.get_hms().hours() == 1h);
    assert(t.get_hms().minutes() == 2min);
    assert(t.get_hms().seconds() == 3s);
    assert(t.is_running() == false);}

    {Time t = Time();
    t.start_clock();
    assert(t.is_running() == true);
    sleep(1);
    t.end_clock();
    assert(t.is_running() == false);
    assert(t.get_time() == 1s);}

    {Time t = Time();
    t.start_clock();
    assert(t.is_running() == true);
    sleep(1);
    t.reject_clock();
    assert(t.is_running() == false);
    assert(t.get_time() == 0s);}

    {Time t = Time();
    t.start_clock();
    assert(t.is_running() == true);
    sleep(1);
    t.end_clock();
    assert(t.is_running() == false);
    assert(t.get_time() == 1s);
    t.start_clock();
    assert(t.is_running() == true);
    sleep(1);
    t.reject_clock();
    assert(t.is_running() == false);
    assert(t.get_time() == 1s);}

    try {
        {Time t = Time();
        t.start_clock();
        t.start_clock();}
    } catch(const std::exception& e) {}

    try {
        {Time t = Time();
        t.end_clock();}
    } catch(const std::exception& e) {}

    try {
        {Time t = Time();
        t.reject_clock();}
    } catch(const std::exception& e) {}
}


void assessment_tests() {
    {Assessment a = Assessment();
    assert(a.get_name() == "N/A");
    assert(a.get_weight() == 0);
    assert(a.get_date().get_ymd().year() == std::chrono::year(1900));
    assert(a.get_date().get_ymd().month() == std::chrono::month(1));
    assert(a.get_date().get_ymd().day() == std::chrono::day(1));
    assert(a.get_grade() == 0);}

    {Assessment a = Assessment("Test", 0.5, 2020, 9, 20, 15.2);
    assert(a.get_name() == "Test");
    assert(a.get_weight() == (float)0.5);
    assert(a.get_date().get_ymd().year() == std::chrono::year(2020));
    assert(a.get_date().get_ymd().month() == std::chrono::month(9));
    assert(a.get_date().get_ymd().day() == std::chrono::day(20));
    assert(a.get_grade() == (float)15.2);}

    {Assessment a = Assessment("Another test", 0.9, 2020, 11, 23, 18.4);
    a.set_name("Just a test");
    a.set_weight(0.4);
    a.set_date(2022, 12, 26);
    a.set_grade(17.5);
    assert(a.get_name() == "Just a test");
    assert(a.get_weight() == (float)0.4);
    assert(a.get_date().get_ymd().year() == std::chrono::year(2022));
    assert(a.get_date().get_ymd().month() == std::chrono::month(12));
    assert(a.get_date().get_ymd().day() == std::chrono::day(26));
    assert(a.get_grade() == (float)17.5);}

    try {
        {Assessment a = Assessment();
        a.set_grade(-13.4);
        cout << a.get_grade();}
    } catch(const std::exception& e) {}

    try {
        {Assessment a = Assessment();
        a.set_weight(1.2);
        cout << a.get_weight();}
    } catch(const std::exception& e) {}

    try {
        {Assessment a = Assessment();
        a.set_grade(23.25);
        cout << a.get_grade();}
    } catch(const std::exception& e) {}

    try {
        {Assessment a = Assessment();
        a.set_weight(-0.1);
        cout << a.get_weight();}
    } catch(const std::exception& e) {}
}


void task_tests() {
    {Task t = Task();
    assert(t.get_exercises() == "N/A");
    assert(t.get_starting_date().get_ymd().year() == std::chrono::year(1900));
    assert(t.get_starting_date().get_ymd().month() == std::chrono::month(1));
    assert(t.get_starting_date().get_ymd().day() == std::chrono::day(1));
    assert(t.get_final_date().get_ymd().year() == std::chrono::year(1900));
    assert(t.get_final_date().get_ymd().month() == std::chrono::month(1));
    assert(t.get_final_date().get_ymd().day() == std::chrono::day(1));
    assert(t.get_completed() == false);}
    
    {Task t = Task("Test", 2020, 9, 20, 2020, 9, 21, true);
    assert(t.get_exercises() == "Test");
    assert(t.get_starting_date().get_ymd().year() == std::chrono::year(2020));
    assert(t.get_starting_date().get_ymd().month() == std::chrono::month(9));
    assert(t.get_starting_date().get_ymd().day() == std::chrono::day(20));
    assert(t.get_final_date().get_ymd().year() == std::chrono::year(2020));
    assert(t.get_final_date().get_ymd().month() == std::chrono::month(9));
    assert(t.get_final_date().get_ymd().day() == std::chrono::day(21));
    assert(t.get_completed() == true);}

    {Task t = Task("Another test", 2020, 11, 23, 2020, 11, 24, false);
    t.set_exercises("Just a test");
    t.set_final_date(2022, 12, 27);
    t.set_starting_date(2022, 12, 26);
    t.set_completed(true);
    assert(t.get_exercises() == "Just a test");
    assert(t.get_starting_date().get_ymd().year() == std::chrono::year(2022));
    assert(t.get_starting_date().get_ymd().month() == std::chrono::month(12));
    assert(t.get_starting_date().get_ymd().day() == std::chrono::day(26));
    assert(t.get_final_date().get_ymd().year() == std::chrono::year(2022));
    assert(t.get_final_date().get_ymd().month() == std::chrono::month(12));
    assert(t.get_final_date().get_ymd().day() == std::chrono::day(27));
    assert(t.get_completed() == true);}

    try {
        {Task t = Task("", 2020, 1, 1, 2019, 12, 12, false);}
    } catch (const invalid_argument& e) {}

    try {
        {Task t = Task();
        t.set_starting_date(2019, 12, 12);}
    } catch (const invalid_argument& e) {}

    try {
        {Task t = Task();
        t.set_dates(2019, 12, 12, 1995, 12, 28);}
    } catch (const invalid_argument& e) {}
}


void summary_tests() {}
void subject_tests() {}
void semester_tests() {}
void course_tests() {}

void Temporary() {}


int main() {
    Date_tests();
    time_tests();
    assessment_tests();
    task_tests();
    summary_tests();
    subject_tests();
    semester_tests();
    course_tests();
    Temporary();
    return 0;
}