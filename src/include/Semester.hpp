#ifndef SEMESTER_H
#define SEMESTER_H
#include "Date.hpp"
#include "Subject.hpp"
#include <vector>
#include <string>

class Semester {
    public:
        Semester();
        Semester(int year, int semester, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day);

        int get_year() const;
        int get_semester() const;
        Date get_starting_date() const;
        Date get_final_date() const;

        void set_year(int year);
        void set_semester(int semester);
        void set_starting_date(int year, int month, int day);
        void set_final_date(int year, int month, int day);

        void create_subject(std::string name, std::string acronym, std::string code, float credits);
        std::vector<Subject>& access_subjects();
        
    private:
        int year_;
        int semester_;
        Date starting_date_;
        Date final_date_;
        std::vector<Subject> subjects_;
};

#endif