#ifndef DATE_H
#define DATE_H
#include <chrono>
#include <string>

class Date {
    public:
        Date(); // Assume current time
        Date(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned minute, unsigned second);

        std::chrono::duration<int> operator-(const Date& d);
        std::chrono::duration<int> seconds() const;
        std::chrono::year_month_day ymd() const;
        //std::chrono::hh_mm_ss hms() const;

        std::string str() const;

    private:
        std::chrono::time_point<std::chrono::system_clock> time_;
};

#endif