#ifndef ASSESSMENT_H
#define ASSESSMENT_H
#include <string>
#include "Date.hpp"

class Assessment {
    public:
        Assessment();
        Assessment(std::string name, float weight, int year, int month, int day, float grade_);

        std::string get_name() const;
        float get_weight() const;
        std::chrono::year_month_day get_date() const;
        float get_grade() const;
        void set_name(std::string const name);
        void set_weight(float weight);
        void set_date(int year, int month, int day);
        void set_grade(float grade);

    private:
        std::string name_;
        float weight_;
        Date date_;
        float grade_;
};

#endif