#include "include/Assessment.hpp"
#include <string>
#include <stdexcept>
using namespace std;

Assessment::Assessment() {
    date_ = Date(1900, 1, 1, 0, 0, 0);
    name_ = "N/A";
    weight_ = 0;
    grade_ = 0;
}

Assessment::Assessment(std::string name, float weight, int year, int month, int day, float grade) {
    if (weight < 0 or weight > 1) {
        throw std::runtime_error("Invalid weight: 0 <= weight <= 1");
    }
    if (grade < 0 or grade > 20) {
        throw std::runtime_error("Invalid grade: 0 <= grade <= 20");
    }
    date_ = Date(year, month, day, 1, 1, 1);
    name_ = name;
    weight_ = weight;
    grade_ = grade;
}

std::string Assessment::get_name() const {
    return name_;
}

float Assessment::get_weight() const {
    return weight_;
}

Date Assessment::get_date() const {
    return date_;
}

float Assessment::get_grade() const {
    return grade_;
}

void Assessment::set_name(std::string const name) {
    name_ = name;
}

void Assessment::set_weight(float weight) {
    if (weight < 0 or weight > 1) {
        throw std::runtime_error("Invalid weight: 0 <= weight <= 1");
    }
    weight_ = weight;
}

void Assessment::set_date(int year, int month, int day) {
    date_.set_ymd(year, month, day);
}

void Assessment::set_grade(float grade) {
    if (grade < 0 or grade > 20) {
        throw std::runtime_error("Invalid grade: 0 <= grade <= 20");
    }
    grade_ = grade;
}
