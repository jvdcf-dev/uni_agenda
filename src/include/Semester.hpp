#ifndef SEMESTER_H
#define SEMESTER_H
#include "Date.hpp"
#include "Subject.hpp"
#include <vector>
#include <string>

class Semester {
    public:
        Semester();
        Semester(int year, int semester, Date starting_date, Date final_date);

        int get_year() const;
        int get_semester() const;
        Date get_starting_date() const;
        Date get_final_date() const;

        void set_year(int year);
        /// @brief 
        /// @param semester 
        void set_semester(int semester);
        void set_starting_date(Date starting_date);
        void set_final_date(Date final_date);

        void create_subject(std::string name, std::string acronym, std::string code, float credits);
        std::vector<Subject>& access_subjects();
        
    private:
        int year_;
        int semester_;
        Date starting_date_;
        Date final_date;
        std::vector<Subject> subjects_;
};

#endif