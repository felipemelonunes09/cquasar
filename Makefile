# Define the compiler and compilation flags
CXX = g++ 
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Find all .cpp files in the current directory and subdirectories
SRC = $(shell find . -name '*.cpp')

# Name of the executable
TARGET = bin/compiler

# Object files to be created from the .cpp files
OBJ = $(patsubst %.cpp, bin/%.o, $(SRC))

# Default rule to build the target
all: $(TARGET)

# Rule to create the executable from object files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to create object files in the respective bin subdirectories
bin/%.o: %.cpp
	@mkdir -p $(dir $@)  # Create the directory for the object file if it doesn't exist
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -rf bin/*.o $(TARGET)

# Phony targets
.PHONY: all clean
