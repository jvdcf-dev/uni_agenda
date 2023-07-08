#ifndef DATE_H
#define DATE_H
#include <ctime>
#include <string>

class Date {
    public:
        Date(); // Assume current UTC time
        Date(time_t seconds); // Number of seconds since 1/1/1900
        Date(unsigned year, unsigned month, unsigned day); // Assume hour = 0, minute = 0 and second = 0
        time_t operator-(const Date& d);
        time_t seconds() const;
        std::string str() const;

    private:
        tm* gmtime_;
};

#endif