#ifndef DATE_H
#define DATE_H
#include <chrono>
#include <string>

class Date {
    public:
        Date();     // Sets the date to the current date and time
        Date(int year, int month, int day, int hour, int minute, int second);

        std::chrono::duration<int64_t> operator-(const Date& d);    // Returns the difference in seconds
        bool operator<(const Date& d);
        bool operator>(const Date& d);
        bool operator<=(const Date& d);
        bool operator>=(const Date& d);
        std::chrono::year_month_day get_ymd() const;
        std::chrono::hh_mm_ss<std::chrono::duration<int64_t>> get_hms() const;
        int get_weekday() const;    // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
        void set_ymd(int year, int month, int day); 
        void set_hms(int hour, int minute, int second); 

        std::string str() const;    // Returns a string in the format "Week Mon Day HH:MM:SS Year\n"
        std::string print_date() const;    // Returns a string in the format "Day/Mon/Year"

    private:
        std::chrono::system_clock::time_point time_;
};

#endif