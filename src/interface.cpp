#include "include/Date.hpp"
#include "include/Time.hpp"
#include "include/Assessment.hpp"
#include "include/Task.hpp"
#include "include/Summary.hpp"
#include "include/Subject.hpp"
#include "include/Semester.hpp"
#include "include/Course.hpp"
#include "include/test.hpp"
#include "include/tabulate/tabulate.hpp"
// created by @p-ranav (see https://github.com/p-ranav/tabulate)
#include <iostream>
using namespace std;


// Create or load
void new_assessment(Subject& s) {}

void new_task(Subject& s) {}

void new_summary(Subject& s) {}

void new_subject(Semester& s) {
    system("clear");
    tabulate::Table menu;
    menu.add_row({"New subject"});
    cout << menu << '\n';
    
    string name, acronym, code;
    float credits;
    cout << "Subject name: ";
    cin >> name;
    cout << "Acronym: ";
    cin >> acronym;
    cout << "Subject code: ";
    cin >> code;
    cout << "Total number of credits: ";
    cin >> credits;
    s.create_subject(name, acronym, code, credits);
}

void new_semester(Course& c) {
    system("clear");
    tabulate::Table menu;
    menu.add_row({"New semester"});
    cout << menu << '\n';

    unsigned year, semester, s_year, s_month, s_day, e_year, e_month, e_day;
    cout << "School year: ";
    cin >> year;
    cout << "Semester: ";
    cin >> semester;
    cout << "Start date (Year): ";
    cin >> s_year;
    cout << "Start date (Month): ";
    cin >> s_month;
    cout << "Start date (Day): ";
    cin >> s_day;
    cout << "End date (Year): ";
    cin >> e_year;
    cout << "End date (Month): ";
    cin >> e_month;
    cout << "End date (Day): ";
    cin >> e_day;
    c.create_semester(year, semester, s_year, s_month, s_day, e_year, e_month, e_day);
}

Course new_course() {
    tabulate::Table menu;
    string name;
    menu.add_row({"New course"});
    cout << menu << '\n';
    cout << "Name of the course: ";
    cin >> name;
    Course c(name);
    return c;
}


Course load_course() {
    return Course("Load course TODO!");
}


// Views
void view_time(Subject& s) {}

void view_assessments(Subject& s) {}

void view_tasks(Subject& s) {}

void view_summaries(Subject& s) {}

void view_subject(Subject& s) {
    system("clear");
    tabulate::Table menu;
    menu.add_row({s.get_name()});
    menu.add_row({"Acronym: " + s.get_acronym() + "\nCode: " + s.get_code() + "\nTotal number of credits: " + to_string(s.get_credits()) + '\n'});
    cout << menu << '\n';
    cout << "Select a option: \n"
        << "1) Time tracked\n"
        << "2) Assessments\n"
        << "3) Tasks\n"
        << "4) Summaries\n";
    unsigned input = 5;
    while ((input > 4) & (input < 0)) (cin >> input);
    if (input == 1) {
        view_time(s);
    } else if (input == 2) {
        view_assessments(s);
    } else if (input == 3) {
        view_tasks(s);
    } else if (input == 4) {
        view_summaries(s);
    }
}

void view_semester(Semester& s) {
    system("clear");
    string halt;
    tabulate::Table menu;
    menu.add_row({"#" + to_string(s.get_year()) + '.' + to_string(s.get_semester())});
    menu.add_row({"Starting date: " + s.get_starting_date().print_date() + "\nEnding date: " + s.get_final_date().print_date() + '\n'});
    cout << menu << '\n';
    cout << "Select a subject: \n";

    unsigned count = 0;
    for (Subject sub: s.access_subjects()) {
        count++;
        cout << count << ") " << sub.get_name() << '\n';
    }
    cout << '\n' << "0) Or, create a new subject" << '\n';

    unsigned input = count + 1;
    while (input > count) (cin >> input);
    if (input == 0) {
        new_subject(s);
        view_subject(s.access_subjects().at(0));
    } else if (input <= count) view_subject(s.access_subjects().at(input - 1));
}

void view_course(Course& c) {
    system("clear");
    tabulate::Table menu;
    menu.add_row({c.get_name()});
    menu.add_row({"Select a semester:"});
    cout << menu;
    unsigned count = 0;
    for (Semester s: c.access_semesters()) {
        count++;
        cout << count << ") #" << s.get_year() << '.' << s.get_semester() << '\n';
    }
    cout << '\n' << "0) Or, create a new semester" << '\n';
    
    unsigned input = count + 1;
    while (input > count) (cin >> input);
    if (input == 0) {
        new_semester(c);
        view_semester(c.access_semesters().at(0));
    } else if (input <= count) view_semester(c.access_semesters().at(input - 1));
}

// Initial and debug interfaces
int main(int argc, char* argv[]) {
    if ((argc == 2) && (string(argv[1]) == string("debug"))) {
        Test execute;
        execute.all_tests();
        return 0;
    } else if (argc != 1) {
        cout << "Invalid arguments!\n"
            << "Usage:\n"
            << "[no arguments] - open the interface\n"
            << "debug - execute all unit tests\n";
        return 127;
    }

    system("clear");    // Only valid for Unix machines (use "cls" for Windows)
    tabulate::Table welcome;
    unsigned input = 4;
    welcome.add_row({"Welcome to uni_agenda!"});
    welcome.add_row({"1) Create a new course\n2) Load a course from a file\n3) About\nCtrl + C) Quit"});
    cout << welcome << '\n';

    while (input > 3) {cin >> input;}
    system("clear");    // Only valid for Unix machines (use "cls" for Windows)

    if (input == 1) {
        Course c = new_course();
        view_course(c);
    } else if (input == 2) {
        Course c = load_course();
        view_course(c);
    } else if (input == 3) {
        cout << "TODO: About\n" << "https://github.com/jvdcf/uni_agenda\n";
    }
    return 0;
}