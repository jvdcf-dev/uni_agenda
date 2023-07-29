#ifndef ASSESSMENT_H
#define ASSESSMENT_H
#include "Date.hpp"
#include <string>

class Assessment {
    public:
        Assessment();
        Assessment(std::string name, float weight, int year, int month, int day, float grade);

        std::string get_name() const;
        float get_weight() const;
        Date get_date() const;
        float get_grade() const;
        
        void set_name(std::string const name);
        void set_weight(float weight);
        void set_date(int year, int month, int day);
        void set_grade(float grade);

    private:
        std::string name_;
        float weight_;      // 0.0 to 1.0
        Date date_;
        float grade_;       // 0.0 to 20.0
};

#endif