#include "include/Subject.hpp"
#include "include/Time.hpp"
#include "include/Assessment.hpp"
#include "include/Task.hpp"
#include "include/Summary.hpp"
#include <vector>
#include <string>
using namespace std;

Subject::Subject() {
    name_ = "N/A";
    acronym_ = "N/A";
    code_ = "N/A";
    credits_ = 0;
    time_tracked_ = Time();
}

Subject::Subject(string name, string acronym, string code, float credits) {
    name_ = name;
    acronym_ = acronym;
    code_ = code;
    credits_ = credits;
    time_tracked_ = Time();
}

string Subject::get_name() const {return name_;}
string Subject::get_acronym() const {return acronym_;}
string Subject::get_code() const {return code_;}
float Subject::get_credits() const {return credits_;}
void Subject::set_name(string name) {name_ = name;}
void Subject::set_acronym(string acronym) {acronym_ = acronym;}
void Subject::set_code(string code) {code_ = code;}
void Subject::set_credits(float credits) {credits_ = credits;}

void Subject::create_assessment(string name, float weight, int year, int month, int day, float grade_) {
    assessments_.push_back(Assessment(name, weight, year, month, day, grade_));
}

void Subject::create_task(string exercises, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day, bool completed) {
    tasks_.push_back(Task(exercises, s_year, s_month, s_day, e_year, e_month, e_day, completed));
}

void Subject::create_summary(string topics, int year, int month, int day, bool reviewed) {
    summaries_.push_back(Summary(topics, year, month, day, reviewed));
}

vector<Assessment>& Subject::access_assessments() {return assessments_;}
vector<Task>& Subject::access_tasks() {return tasks_;}
vector<Summary> &Subject::access_summaries() { return summaries_; }
Time& Subject::access_time() {return time_tracked_;}

float Subject::grade() const {
    float sum = 0;
    for (Assessment a: assessments_) {
        sum += a.get_grade() * a.get_weight();
        }
    return sum / assessments_.size();
}
