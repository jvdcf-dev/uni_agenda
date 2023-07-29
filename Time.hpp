#ifndef TIME_H
#define TIME_H
#include "Date.hpp"
#include <chrono>

class Time {
    public:
        Time();
        Time(int hours, int minutes, int seconds);

        void start_clock();
        void reject_clock();
        void end_clock();
        std::chrono::duration<int64_t> weekly_average(int weeks) const;

        std::chrono::duration<int64_t> get_time() const;
        std::chrono::hh_mm_ss<std::chrono::duration<int64_t>> get_hms() const;
        bool is_running() const;
        void set_time(int hours, int minutes, int seconds);

    private:
        Date starting_date_;
        bool running_;
        std::chrono::duration<int64_t> time_tracked_;
};

#endif
