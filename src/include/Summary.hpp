#ifndef SUMMARY_H
#define SUMMARY_H
#include "Date.hpp"
#include <string>

class Summary {
    public:
        Summary();
        Summary(std::string topics, int year, int month, int day, bool reviewed);

        std::string get_topics() const;
        Date get_date() const;
        bool get_reviewed() const;
        void set_topics(std::string topics);
        void set_date(int year, int month, int day);
        void set_reviewed(bool reviewed);
        
    private:
        std::string topics_;
        Date date_;
        bool reviewed_;
};

#endif