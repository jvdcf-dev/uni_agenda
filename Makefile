# Project hierarchy:
# uni_agenda/
# ├── $(SRC_DIR)/			# Source files (.cpp)
# |   └── include/  # Headers (.hpp)
# ├── obj/			# Objects (.o)
# ├── bin/			# Executables
# ├── docs/			# Documentation
# ├── Makefile
#
# Classes:
# Date, Assessment, Time, Task, Summary, Subject, Semester, Course


# Project name
PROJECT = uni_agenda

# Compiler
COMPILER = g++

# Flags: Includes c++ version, warnings as errors, debugging info, math library, sanitizers and optimization
FLAGS = -std=c++20 -pedantic -Wall -Wuninitialized -Werror -g -lm -fsanitize=address -fsanitize=undefined -O2

# Directories and files
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Programs to compile
PROGRAMS = test

# Make actions / arguments
all: $(PROGRAMS)

test: date assessment time task summary # subject semester course
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/test.cpp -o $(OBJ_DIR)/test.o
	$(COMPILER) $(FLAGS) -flto=thin $(OBJ_DIR)/* -o $(BIN_DIR)/test


date:
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/Date.cpp -o $(OBJ_DIR)/date.o

assessment:
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/Assessment.cpp -o $(OBJ_DIR)/assessment.o

time:
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/Time.cpp -o $(OBJ_DIR)/time.o

task:
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/Task.cpp -o $(OBJ_DIR)/task.o

summary:
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/Summary.cpp -o $(OBJ_DIR)/summary.o

subject:
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/Subject.cpp -o $(OBJ_DIR)/subject.o

semester:
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/Semester.cpp -o $(OBJ_DIR)/semester.o

course:
	$(COMPILER) $(FLAGS) -c $(SRC_DIR)/Course.cpp -o $(OBJ_DIR)/course.o


clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*