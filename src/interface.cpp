#include "include/Date.hpp"
#include "include/Time.hpp"
#include "include/Assessment.hpp"
#include "include/Task.hpp"
#include "include/Summary.hpp"
#include "include/Subject.hpp"
#include "include/Semester.hpp"
#include "include/Course.hpp"
#include "include/test.hpp"
#include <ncurses.h>  // CLI interface
#include <iostream>
using namespace std;

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

    initscr();
    WINDOW* tw = newwin(5, 20, 0, 0);  // testing window (height, width, starty, startx)

    refresh();

    box(tw, 0, 0);
    mvwprintw(tw, 0, 2, "Testing window ");
    move(1, 1);

    wrefresh(tw);

    int c = getch();
    printw("%d", c);
    refresh();
    getch();
    endwin();
    return 0;
}