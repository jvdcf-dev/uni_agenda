#include "include/Summary.hpp"
#include "include/Date.hpp"
#include <string>

Summary::Summary() {
    topics_ = "N/A";
    date_ = Date(1900, 1, 1, 0, 0, 0);
    reviewed_ = false;
}

Summary::Summary(std::string topics, int year, int month, int day, bool reviewed) {
    topics_ = topics;
    date_ = Date(year, month, day, 1, 1, 1);
    reviewed_ = reviewed;
}

std::string Summary::get_topics() const {return topics_;}
Date Summary::get_date() const {return date_;}
bool Summary::get_reviewed() const {return reviewed_;}
void Summary::set_topics(std::string topics) {topics_ = topics;}
void Summary::set_date(int year, int month, int day) {date_.set_ymd(year, month, day);}
void Summary::set_reviewed(bool reviewed) {reviewed_ = reviewed;}
