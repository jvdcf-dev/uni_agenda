#include "include/Time.hpp"
#include <stdexcept>
#include <chrono>
using namespace std::chrono;

Time::Time() {
    starting_date_ = Date();
    running_ = false;
    time_tracked_ = duration<int64_t>(0);
}

Time::Time(int hours, int minutes, int seconds) {
    starting_date_ = Date();
    running_ = false;
    time_tracked_ = duration<int64_t>(hours * 3600 + minutes * 60 + seconds);
}

void Time::start_clock() {
    if (running_ == true) throw std::runtime_error("Clock already running: use reject_clock() instead");
    starting_date_ = Date();
    running_ = true;
}

void Time::reject_clock() {
    if (running_ == false) throw std::runtime_error("Clock not running: use start_clock() before");
    running_ = false;
}

void Time::end_clock() {
    if (running_ == false) throw std::runtime_error("Clock not running: use start_clock() before");
    time_tracked_ += Date() - starting_date_;
    running_ = false;
}

duration<int64_t> Time::weekly_average(int weeks) const {
    return time_tracked_ / weeks / 25200;
}

duration<int64_t> Time::get_time() const {
    return time_tracked_;
}

hh_mm_ss<::duration<int64_t>> Time::get_hms() const {
    auto days = floor<::duration<int, std::ratio_multiply<::hours::period, std::ratio<24>>>>(time_tracked_);
    auto hours = time_tracked_ - days;
    hh_mm_ss hms{hours};
    return hms;
}

bool Time::is_running() const {
    return running_;
}

void Time::set_time(int hours, int minutes, int seconds) {
    time_tracked_ = duration<int64_t>(hours * 3600 + minutes * 60 + seconds);
}
