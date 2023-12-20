# Makefile for Minesweeper game

# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -Wall -g

# Source directory
SRC_DIR = src

# Binary directory
BIN_DIR = bin

# Target executable name
TARGET = minesweeper

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)

# Build target
$(BIN_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
	rm -rf $(BIN_DIR)

