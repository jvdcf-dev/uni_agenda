#include "Date.hpp"
#include <chrono>
#include <sstream>
#include <stdexcept>
using namespace std::chrono;

Date::Date() {
    time_ = system_clock::now();
}

Date::Date(int year = 1900, int month = 1, int day = 1, int hour = 0, int minute = 0, int second = 0) {
    if (year < 1754) throw std::runtime_error("Invalid date");
    std::tm point_in_time = {second, minute, hour, day, month - 1, year - 1900};
    point_in_time.tm_isdst = -1;
    time_ = system_clock::from_time_t(std::mktime(&point_in_time));
}

duration<int64_t> Date::operator-(const Date &d) {
    auto duration = time_.time_since_epoch() - d.time_.time_since_epoch();
    return round<seconds>(duration);
}

bool Date::operator<(const Date &d) {
    return time_ < d.time_;
}

bool Date::operator>(const Date &d) {
    return time_ > d.time_;
}

bool Date::operator<=(const Date &d) {
    return time_ <= d.time_;
}

bool Date::operator>=(const Date &d) {
    return time_ >= d.time_;
}

year_month_day Date::get_ymd() const {
    auto days = floor<duration<int, std::ratio_multiply<hours::period, std::ratio<24>>>>(time_);
    year_month_day ymd{days};
    return ymd;
}

int Date::get_weekday() const {
    time_t time_t = system_clock::to_time_t(time_);
    std::tm tm = *std::localtime(&time_t);
    return tm.tm_wday;
}

void Date::set_ymd(int year, int month, int day) {
    if (year < 1754) throw std::runtime_error("Invalid date");
    time_t time_t = system_clock::to_time_t(time_);
    std::tm old_tm = *std::localtime(&time_t);
    std::tm new_tm = {old_tm.tm_sec, old_tm.tm_min, old_tm.tm_hour, day, month - 1, year - 1900};
    time_t = std::mktime(&new_tm);
    time_ = system_clock::from_time_t(time_t);
}

void Date::set_hms(int hour, int minute, int second) {
    time_t time_t = system_clock::to_time_t(time_);
    std::tm old_tm = *std::localtime(&time_t);
    std::tm new_tm = {second, minute, hour, old_tm.tm_mday, old_tm.tm_mon, old_tm.tm_year};
    time_t = std::mktime(&new_tm);
    time_ = system_clock::from_time_t(time_t);
}

hh_mm_ss<duration<int64_t>> Date::get_hms() const {
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
