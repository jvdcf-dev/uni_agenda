# Compiler
COMPILER=g++

# Flags
# Includes c++ version, warnings as errors, debugging info, math library and sanitizers
FLAGS=-std=c++20 -pedantic -Wall -Wuninitialized -Werror -g -lm -fsanitize=address -fsanitize=undefined

# Files and Headers used in all programs
FILES=
HEADERS=

# Compilated programs
PROGRAMS= #(TODO)

# Make actions / arguments
all: $(PROGRAMS)

clean: rm -fr *.dSYM $(PROGRAMS)

# (TODO)

# $(PROG): $(FILES) $(HEADERS)
# 	$(COMPILER) $(FLAGS) $(FILES) -o $(PROG)