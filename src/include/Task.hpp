#ifndef TASK_H
#define TASK_H
#include <string>
#include "Date.hpp"

class Task {
    public:
        Task();
        Task(std::string exercises, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day, bool completed);

        std::string get_exercises() const;
        Date get_starting_date() const;
        Date get_final_date() const;
        bool get_completed() const;
        
        void set_exercises(std::string const exercises);
        void set_starting_date(int year, int month, int day);
        void set_final_date(int year, int month, int day);
        void set_dates(int s_year, int s_month, int s_day, int e_year, int e_month, int e_day);
        void set_completed(bool completed);

    private:
        std::string exercises_;
        Date starting_date_;
        Date final_date_;
        bool completed_;
};

#endif