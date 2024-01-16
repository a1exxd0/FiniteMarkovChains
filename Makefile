# Makefile

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Source files
SRC = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC))

# Executable name
EXEC = FiniteMarkovChains

# Rule to build the executable
$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

# Rule to build object files from source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up
clean:
	rm -rf $(BUILD_DIR) $(EXEC)
