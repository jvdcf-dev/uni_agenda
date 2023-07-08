#include "Date.hpp"
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

Date::Date() {
    time_t current_time = time(0);
    gmtime_ = gmtime(&current_time);
}

Date::Date(time_t seconds) {
    time_t current_time = seconds;
    gmtime_ = gmtime(&current_time);
}

Date::Date(unsigned year, unsigned month, unsigned day) {
    gmtime_ = {};
    gmtime_->tm_sec = 0;
    gmtime_->tm_min = 0;
    gmtime_->tm_hour = 0;
    gmtime_->tm_mday = day;
    gmtime_->tm_mon = month - 1;
    gmtime_->tm_year = year - 1900;
    //gmtime_->tm_wday
    //gmtime_->tm_yday
    //gmtime_->tm_isdst
}

time_t Date::operator-(const Date &d) {
    time_t left = mktime(gmtime_);
    time_t right = mktime(d.gmtime_);
    return left - right;
}

time_t Date::seconds() const {
    return mktime(gmtime_);
}

string Date::str() const {
    time_t seconds = mktime(gmtime_);
    return ctime(&seconds);
}
