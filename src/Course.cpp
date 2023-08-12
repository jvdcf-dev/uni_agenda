#include "include/Course.hpp"
#include "include/Semester.hpp"
#include <vector>
#include <string>
using namespace std;

Course::Course() {
    name_ = "N/A";
}

Course::Course(std::string name) {
    name_ = name;
}

std::string Course::get_name() const {
    return name_;
}

void Course::set_name(std::string name) {
    name_ = name;
}

void Course::create_semester(int year, int semester, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day) {
    Semester s(year, semester, s_year, s_month, s_day, e_year, e_month, e_day);
    semesters_.push_back(s);
}

std::vector<Semester>& Course::access_semesters() {
    return semesters_;
}

void Course::save_course(std::string path) {
    // TODO
}

void Course::load_course(std::string path) {
    // TODO
}
