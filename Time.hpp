#ifndef TIME_H
#define TIME_H
#include "Date.hpp"
#include <chrono>

class Time {
    public:
        Time();
        Time(int hours, int minutes, int seconds);

        void start_clock();
        void end_clock();
        std::chrono::duration<int64_t> weekly_average(int weeks) const;

        std::chrono::duration<int64_t> get_time() const;
        void set_time(int hours, int minutes, int seconds);

    private:
        Date starting_date_;
        Date final_date_;
        std::chrono::duration<int64_t> time_tracked_;
};

#endif
