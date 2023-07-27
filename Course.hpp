#ifndef COURSE_H
#define COURSE_H
#include "Semester.hpp"
#include <vector>

class Course {
    public:
        Course();
        Course(std::string name);

        std::string get_name() const;
        void set_name(std::string name);

        void create_semester(int year, int semester, Date starting_date, Date final_date);
        std::vector<Semester>& access_semesters();
        
    private:
        std::string name;
        std::vector<Semester> semesters;
};

#endif