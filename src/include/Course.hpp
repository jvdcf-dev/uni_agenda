#ifndef COURSE_H
#define COURSE_H
#include "Semester.hpp"
#include <vector>
#include <string>

class Course {
    public:
        Course();
        Course(std::string name);

        std::string get_name() const;
        void set_name(std::string name);

        void create_semester(int year, int semester, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day);
        std::vector<Semester>& access_semesters();
        
        void save_course(std::string path);
        void load_course(std::string path);

    private:
        std::string name_;
        std::vector<Semester> semesters_;
};

#endif