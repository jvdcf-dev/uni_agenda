# Compiler
COMPILER=g++

# Flags
# Includes c++ version, warnings as errors, debugging info, math library and sanitizers
FLAGS=-std=c++20 -pedantic -Wall -Wuninitialized -Werror -g -lm -fsanitize=address -fsanitize=undefined

# Files and Headers used in all programs
FILES=Date.cpp
HEADERS=Date.hpp

# Compilated programs
PROGRAMS=test #TODO

# Make actions / arguments
all: $(PROGRAMS)

test: $(HEADERS) $(FILES) test.cpp 
	$(COMPILER) -o test test.cpp $(FILES) $(FLAGS)

clean: rm -fr *.dSYM $(PROGRAMS)

# (TODO)

# $(PROG): $(FILES) $(HEADERS)
# 	$(COMPILER) $(FLAGS) $(FILES) -o $(PROG)$(FILES) $(HEADERS) $(COMPILER) $(FLAGS) $(FILES) -o test