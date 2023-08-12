#include "include/Semester.hpp"
#include "include/Date.hpp"
#include "include/Subject.hpp"
#include <vector>
#include <string>
#include "Semester.hpp"
using namespace std;

Semester::Semester() {
}

Semester::Semester(int year, int semester, Date starting_date, Date final_date) {
}

int Semester::get_year() const {
    return 0;
}

int Semester::get_semester() const {
    return 0;
}

Date Semester::get_starting_date() const {
    return Date();
}

Date Semester::get_final_date() const {
    return Date();
}

void Semester::set_year(int year) {
}

void Semester::set_semester(int semester) {
}

void Semester::set_starting_date(Date starting_date) {
}

void Semester::set_final_date(Date final_date) {
}

void Semester::create_subject(std::string name, std::string acronym, std::string code, float credits) {
}

std::vector<Subject> &Semester::access_subjects() {
    // TODO: insert return statement here
}
