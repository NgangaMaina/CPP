# Makefile for C++ Development
# Usage:
#   make <filename>        - Compile filename.cpp
#   make run <filename>    - Compile and run filename.cpp
#   make debug <filename>  - Debug filename.cpp with gdb
#   make val <filename>    - Run filename.cpp with valgrind
#   make clean             - Remove all compiled files

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic
DEBUGFLAGS := -g -O0 -DDEBUG
RELEASEFLAGS := -O2 -DNDEBUG

# Get the target from command line arguments
TARGET := $(filter-out run debug val clean help,$(MAKECMDGOALS))

# If no target specified, use main
ifeq ($(TARGET),)
TARGET := main
endif

SRC := $(TARGET).cpp

# Dummy targets to prevent make from treating arguments as targets
.PHONY: run debug val clean help $(TARGET)

# Default: just compile
$(TARGET):
	@echo "Compiling $(SRC)..."
	@$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) -o $(TARGET) $(SRC)
	@echo "✓ Compiled: $(TARGET)"

# Compile and run
run:
	@echo "Compiling $(SRC)..."
	@$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) -o $(TARGET) $(SRC)
	@echo "Running $(TARGET)..."
	@echo "----------------------------------------"
	@./$(TARGET)
	@echo "----------------------------------------"

# Debug with gdb
debug:
	@echo "Compiling $(SRC) with debug flags..."
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(SRC)
	@echo "Starting GDB..."
	@echo "Useful commands: break main, run, next, step, print <var>, quit"
	@echo "----------------------------------------"
	@gdb ./$(TARGET)

# Memory check with valgrind
val:
	@echo "Compiling $(SRC) with debug flags..."
	@$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(SRC)
	@echo "Running valgrind..."
	@echo "----------------------------------------"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Clean all executables
clean:
	@echo "Cleaning up..."
	@rm -f *.out *.o
	@find . -maxdepth 1 -type f -executable -exec rm -f {} +
	@echo "✓ Clean complete"

# Help
help:
	@echo "C++ Makefile - Short Commands"
	@echo ""
	@echo "Usage:"
	@echo "  make <filename>        - Compile filename.cpp"
	@echo "  make run <filename>    - Compile and run filename.cpp"
	@echo "  make debug <filename>  - Debug filename.cpp with gdb"
	@echo "  make val <filename>    - Check memory with valgrind"
	@echo "  make clean             - Remove all compiled files"
	@echo ""
	@echo "Examples:"
	@echo "  make test              - Compiles test.cpp"
	@echo "  make run test          - Compiles and runs test.cpp"
	@echo "  make debug main        - Debugs main.cpp"
	@echo "  make val calculator    - Runs valgrind on calculator.cpp"
	@echo ""
	@echo "Note: Don't include .cpp extension in filename"

# Make the filename argument not error out
%:
	@:
