#include "Task.hpp"
#include <stdexcept>
using namespace std;

Task::Task() {
    exercises_ = "N/A";
    starting_date_ = Date(1900, 1, 1, 0, 0, 0);
    final_date_ = Date(1900, 1, 1, 0, 0, 0);
    completed_ = false;
}

Task::Task(std::string exercises, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day, bool completed) {
    exercises_ = exercises;
    starting_date_ = Date(s_year, s_month, s_day, 1, 1, 1);
    final_date_ = Date(e_year, e_month, e_day, 1, 1, 1);
    completed_ = completed;

    if (starting_date_ > final_date_) {
        throw invalid_argument("Starting date must be before final date.");
    }
}

std::string Task::get_exercises() const {return exercises_;}
Date Task::get_starting_date() const {return starting_date_;}
Date Task::get_final_date() const {return final_date_;}
bool Task::get_completed() const {return completed_;}

void Task::set_exercises(std::string const exercises) {exercises_ = exercises;}

void Task::set_starting_date(int year, int month, int day) {
    if (Date(year, month, day, 0, 0, 0) > final_date_) {
        throw invalid_argument("Starting date must be before final date.");
    }
    starting_date_.set_ymd(year, month, day);
}

void Task::set_final_date(int year, int month, int day) {
    if (starting_date_ > Date(year, month, day, 0, 0, 0)) {
        throw invalid_argument("Starting date must be before final date.");
    }
    final_date_.set_ymd(year, month, day);
}

void Task::set_dates(int s_year, int s_month, int s_day, int e_year, int e_month, int e_day) {
    if (Date(s_year, s_month, s_day, 0, 0, 0) > Date(e_year, e_month, e_day, 0, 0, 0)) {
        throw invalid_argument("Starting date must be before final date.");
    }
    starting_date_.set_ymd(s_year, s_month, s_day);
    final_date_.set_ymd(e_year, e_month, e_day);
}

void Task::set_completed(bool completed) {completed_ = completed;}
