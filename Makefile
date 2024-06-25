CXX := g++
CXXFLAGS := -std=c++17 -fdiagnostics-color=always -g
SFML_INCLUDE := -I/opt/homebrew/Cellar/sfml/2.6.1/include/
SFML_LIB := -L/opt/homebrew/Cellar/sfml/2.6.1/lib/
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR := src
BIN_DIR := bin

# Name of your executable (change this accordingly)
TARGET := main

# Source files (add more .cpp files if your program consists of multiple files)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Object files derived from source files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))

# Rule to compile .cpp files into object files in bin directory
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c $< -o $@

# Rule to link object files into executable
$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SFML_LIB) $^ $(LIBS) -o $@

.PHONY: all clean run

all: clean $(BIN_DIR)/$(TARGET)

clean:
	@rm -rf $(BIN_DIR)

run: $(BIN_DIR)/$(TARGET)
	@$(BIN_DIR)/$(TARGET)
