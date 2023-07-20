#ifndef DATE_H
#define DATE_H
#include <chrono>
#include <string>

class Date {
    public:
        Date(); // Assume current time
        Date(int year, int month, int day, int hour, int minute, int second);

        std::chrono::duration<int64_t> operator-(const Date& d);    // Number of seconds
        std::chrono::year_month_day ymd() const;
        std::chrono::hh_mm_ss<std::chrono::duration<int64_t>> hms() const;

        std::string str() const;

    private:
        std::chrono::system_clock::time_point time_;
};

#endif