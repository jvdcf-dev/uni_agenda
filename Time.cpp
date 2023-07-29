#include "Time.hpp"
using namespace std;

Time::Time() {
}

Time::Time(int hours, int minutes, int seconds) {
}

void Time::start_clock() {
}

void Time::end_clock() {
}

std::chrono::duration<int64_t> Time::weekly_average(int weeks) const {
    return std::chrono::duration<int64_t>();
}

std::chrono::duration<int64_t> Time::get_time() const {
    return std::chrono::duration<int64_t>();
}

void Time::set_time(int hours, int minutes, int seconds) {
}
