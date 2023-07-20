#include "Date.hpp"
#include <chrono>
#include <sstream>
using namespace std::chrono;

Date::Date() {
    time_ = system_clock::now();
}

Date::Date(int year = 1900, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0) {
    if (year < 1754) throw "Invalid date";
    std::tm point_in_time = {second, minute, hour, day, month - 1, year - 1900};
    point_in_time.tm_isdst = -1;
    time_ = system_clock::from_time_t(std::mktime(&point_in_time));
}

duration<int64_t> Date::operator-(const Date &d) {
    auto duration = time_.time_since_epoch() - d.time_.time_since_epoch();
    return round<seconds>(duration);
}

year_month_day Date::ymd() const {
    auto days = floor<duration<int, std::ratio_multiply<hours::period, std::ratio<24>>>>(time_);
    year_month_day ymd{days};
    return ymd;
}

hh_mm_ss<duration<int64_t>> Date::hms() const {
    auto days = floor<duration<int, std::ratio_multiply<hours::period, std::ratio<24>>>>(time_);
    auto hours = time_ - days;
    auto rounded_hours = round<seconds>(hours);
    hh_mm_ss hms{rounded_hours};
    return hms;
}

std::string Date::str() const {
    time_t time_point = system_clock::to_time_t(time_);
    return ctime(&time_point);
}
