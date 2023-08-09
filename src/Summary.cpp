#include "include/Summary.hpp"
#include "include/Date.hpp"
#include <string>
#include "Summary.hpp"

Summary::Summary() {
}

Summary::Summary(std::string topics, int year, int month, int day, bool reviewed) {
}

std::string Summary::get_topics() const {
    return std::string();
}

std::chrono::year_month_day Summary::get_date() const {
    return std::chrono::year_month_day();
}

bool Summary::get_reviewed() const {
    return false;
}

void Summary::set_topics(std::string topics) {
}

void Summary::set_date(int year, int month, int day) {
}

void Summary::set_reviewed(bool reviewed) {
}
