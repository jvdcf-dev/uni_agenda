#ifndef TEST_H
#define TEST_H
#include "Date.hpp"
#include "Time.hpp"
#include "Assessment.hpp"
#include "Task.hpp"
#include "Summary.hpp"
#include "Subject.hpp"
#include "Semester.hpp"
#include "Course.hpp"

class Test {
    public:
        Test();
        void all_tests();
        void date_tests();
        void time_tests();
        void assessment_tests();
        void task_tests();
        void summary_tests();
        void subject_tests();
        void semester_tests();
        void course_tests();
        void temporary_tests();
};

#endif