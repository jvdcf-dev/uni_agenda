#ifndef SEMESTER_H
#define SEMESTER_H
#include "Date.hpp"
#include "Subject.hpp"
#include <vector>

class Semester {
    public:

    private:
        int year_;
        int semester_;
        Date starting_date_;
        Date final_date;
        std::vector<Subject> subjects_;
};

#endif