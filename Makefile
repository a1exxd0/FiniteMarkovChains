# Makefile

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
OTHER_SRC_DIR = alglib-4.01.0.cpp.gpl/alglib-cpp/src
INCLUDE_DIR = include
INCLUDE_DIR2 = alglib-4.01.0.cpp.gpl/alglib-cpp/src
BUILD_DIR = build

# Source files
SRC = $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(OTHER_SRC_DIR)/*.cpp)

# Executable name
EXEC = FiniteMarkovChains

# Rule to build the executable
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(INCLUDE_DIR2) $^ -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(EXEC)
