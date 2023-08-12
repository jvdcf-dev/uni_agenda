#include "include/Semester.hpp"
#include "include/Date.hpp"
#include "include/Subject.hpp"
#include <vector>
#include <string>
using namespace std;

Semester::Semester() {
    year_ = 0;
    semester_ = 0;
    starting_date_ = Date();
    final_date_ = Date();
}

Semester::Semester(int year, int semester, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day) {
    year_ = year;
    semester_ = semester;
    starting_date_ = Date(s_year, s_month, s_day, 1, 1, 1);
    final_date_ = Date(e_year, e_month, e_day, 1, 1, 1);
}

int Semester::get_year() const {return year_;}
int Semester::get_semester() const {return semester_;}
Date Semester::get_starting_date() const {return starting_date_;}
Date Semester::get_final_date() const {return final_date_;}
void Semester::set_year(int year) {year_ = year;}
void Semester::set_semester(int semester) {semester_ = semester;}

void Semester::set_starting_date(int year, int month, int day) {starting_date_.set_ymd(year, month, day);}

void Semester::set_final_date(int year, int month, int day) {final_date_.set_ymd(year, month, day);}

void Semester::create_subject(std::string name, std::string acronym, std::string code, float credits) {
    Subject subject(name, acronym, code, credits);
    subjects_.push_back(subject);
}

std::vector<Subject>& Semester::access_subjects() {return subjects_;}
