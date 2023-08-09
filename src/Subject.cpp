#include "include/Subject.hpp"
#include "include/Time.hpp"
#include "include/Assessment.hpp"
#include "include/Task.hpp"
#include "include/Summary.hpp"
#include <vector>
#include <string>
using namespace std;

Subject::Subject() {

}

Subject::Subject(string name, string acronym, string code, float credits) {

}

string Subject::get_name() const {
    return std::string();
}

string Subject::get_acronym() const {
    return std::string();
}

string Subject::get_code() const {
    return std::string();
}

float Subject::get_credits() const {
    return 0.0f;
}

void Subject::set_name(string name) {

}

void Subject::set_acronym(string acronym) {

}

void Subject::set_code(string code) {

}

void Subject::set_credits(float credits) {

}

void Subject::create_assessment(string name, float weight, int year, int month, int day, float grade_) {

}

void Subject::create_task(string exercises, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day, bool completed) {

}

void Subject::create_summary(string topics, int year, int month, int day, bool reviewed) {

}

vector<Assessment>& Subject::access_assessments() {
    
}

vector<Task>& Subject::access_tasks() {
    
}

vector<Summary>& Subject::access_summaries() {

}
