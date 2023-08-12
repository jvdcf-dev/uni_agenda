#include "include/Course.hpp"
#include "include/Semester.hpp"
#include <vector>
#include <string>
#include "Course.hpp"
using namespace std;

Course::Course() {
}

Course::Course(std::string name) {
}

std::string Course::get_name() const {
    return std::string();
}

void Course::set_name(std::string name) {
}

void Course::create_semester(int year, int semester, Date starting_date, Date final_date) {
}

std::vector<Semester> &Course::access_semesters() {
    // TODO: insert return statement here
}

void Course::save_course(std::string path) {
}

void Course::load_course(std::string path) {
}
