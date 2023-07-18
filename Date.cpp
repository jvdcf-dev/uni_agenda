#include "Date.hpp"
#include <chrono>
#include <sstream>
using namespace std::chrono;

Date::Date() {
    time_ = system_clock::now();
}

Date::Date(unsigned year = 0, unsigned month = 1, unsigned day = 1, unsigned hour = 0, unsigned minute = 0, unsigned second = 0) {
    
}

std::chrono::duration<int> Date::operator-(const Date &d) {
    return std::chrono::duration<int>();
}

std::chrono::duration<int> Date::seconds() const {
    return std::chrono::duration<int>();
}

std::chrono::year_month_day Date::ymd() const {
    auto days = floor<duration<int, std::ratio_multiply<hours::period, std::ratio<24>>>>(time_);
    year_month_day ymd{days};
    return ymd;
}

// auto hours = time_ - days;
// hh_mm_ss hms{hours};

std::string Date::str() const {
    time_t time_point = system_clock::to_time_t(time_);
    return ctime(&time_point);
}
