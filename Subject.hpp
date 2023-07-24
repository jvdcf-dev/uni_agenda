#ifndef SUBJECT_H
#define SUBJECT_H
#include "Time.hpp"
#include "Assessment.hpp"
#include "Task.hpp"
#include "Summary.hpp"
#include <vector>
#include <string>

class Subject {
    public:
        // Constructors (no desctructors necessary)
        Subject();
        Subject(std::string name, std::string acronym, std::string code, float credits);

        // Getters
        std::string get_name() const;
        std::string get_acronym() const;
        std::string get_code() const;
        float get_credits() const;

        // Setters
        void set_name(std::string name);
        void set_acronym(std::string acronym);
        void set_code(std::string code);
        void set_credits(float credits);

        // Vector manipulation (unsure)
        void create_assessment(std::string name, float weight, int year, int month, int day, float grade_);
        void create_task(std::string exercises, int s_year, int s_month, int s_day, int e_year, int e_month, int e_day, bool completed);
        void create_summary(std::string topics, int year, int month, int day, bool reviewed);
        std::vector<Assessment>& access_assessments();
        std::vector<Task>& access_tasks();
        std::vector<Summary>& access_summaries();

    private:
        std::string name_;
        std::string acronym_;
        std::string code_;
        float credits_;
        Time time_tracked;
        std::vector<Assessment> assessments_;
        std::vector<Task> tasks_;
        std::vector<Summary> summaries_;
};

#endif