# Project hierarchy:
# uni_agenda/
# ├── src/			# Source files (.cpp)
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
FILES = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/include/*.hpp)
OBJ_DIR = obj
BIN_DIR = bin

# Programs to compile
PROGRAMS=test #TODO


# Make actions / arguments
all: date assessment time task test
	$(COMPILER) $(FLAGS) -flto=thin -o $(OBJ_DIR)/* -o $(PROJECT)
	strip $(PROJECT)

test:
	$(COMPILER) $(FLAGS) -c test.cpp -o $(OBJ_DIR)/test.o

date:
	$(COMPILER) $(FLAGS) -c src/Date.cpp -o $(OBJ_DIR)/date.o

assessment:
	$(COMPILER) $(FLAGS) -c src/Assessment.cpp -o $(OBJ_DIR)/assessment.o

time:
	$(COMPILER) $(FLAGS) -c src/Time.cpp -o $(OBJ_DIR)/time.o

task:
	$(COMPILER) $(FLAGS) -c src/Task.cpp -o $(OBJ_DIR)/task.o



#all: $(PROGRAMS)
#
#test: $(HEADERS) $(FILES) test.cpp
#	$(COMPILER) -o $(BIN_DIR)/test test.cpp $(FILES) $(FLAGS)

