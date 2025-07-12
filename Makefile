# =============================================================================
# Makefile for Minimal Qt Window Program
# =============================================================================
# 
# This Makefile compiles a simple Qt5 GUI application that creates a minimal
# window. It demonstrates the basic Qt5 build process and dependency management.
# 
# The program uses:
# - QApplication: Required for any Qt GUI application (event loop, etc.)
# - QMainWindow: Provides standard window functionality with title bar, etc.
# 
# Build Process:
# 1. Compile source files (.cpp) to object files (.o)
# 2. Link object files with Qt5 libraries to create executable
# 3. Handle Qt5-specific include paths and library linking automatically
# 
# Dependencies:
# - Qt5 development libraries (Qt5Core, Qt5Widgets)
# - pkg-config (for automatic Qt5 detection)
# - g++ compiler with C++11 support
# =============================================================================

# =============================================================================
# COMPILER AND COMPILATION FLAGS
# =============================================================================

# C++ compiler to use
# g++ is the GNU C++ compiler, widely available on Linux systems
CXX = g++

# Compiler flags for C++ compilation
# -std=c++11: Enable C++11 standard features (required for modern Qt5)
# -Wall: Enable all common warning messages
# -Wextra: Enable extra warning messages not covered by -Wall
# -O2: Enable optimization level 2 (good balance of speed vs compile time)
# -g: Include debugging information (uncomment for debugging)
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
# CXXFLAGS = -std=c++11 -Wall -Wextra -O2 -g  # Uncomment for debugging

# =============================================================================
# QT5 SPECIFIC CONFIGURATION
# =============================================================================

# Qt5 include flags (header file paths)
# pkg-config --cflags Qt5Core Qt5Widgets returns the include paths needed
# for Qt5 headers. This automatically detects where Qt5 is installed.
# Examples of what this might return: -I/usr/include/qt5 -I/usr/include/qt5/QtCore
QT5_CXXFLAGS = $(shell pkg-config --cflags Qt5Core Qt5Widgets)

# Qt5 library linking flags
# pkg-config --libs Qt5Core Qt5Widgets returns the library linking flags
# needed to link against Qt5 libraries. This automatically detects the
# correct library paths and linking flags.
# Examples of what this might return: -lQt5Core -lQt5Widgets -lQt5Gui
QT5_LIBS = $(shell pkg-config --libs Qt5Core Qt5Widgets)

# =============================================================================
# PROJECT CONFIGURATION
# =============================================================================

# Name of the final executable that will be created
# This is what you'll run to start the program
TARGET = minimal_qt_window

# List of all C++ source files in the project
# Currently main.cpp, customwindow.cpp, and circle.cpp, but you can add more files here
# Example: SOURCES = main.cpp window.cpp dialog.cpp circle.cpp
SOURCES = main.cpp customwindow.cpp circle.cpp

# Object files that will be created from source files
# This automatically converts .cpp files to .o files
# Example: main.cpp -> main.o, window.cpp -> window.o
OBJECTS = $(SOURCES:.cpp=.o)

# =============================================================================
# BUILD TARGETS
# =============================================================================

# Default target - what gets built when you just run 'make'
# This builds the complete program
all: $(TARGET)

# =============================================================================
# LINKING RULE
# =============================================================================

# Rule to create the final executable by linking object files with Qt5 libraries
# $(TARGET): $(OBJECTS) means "to build TARGET, we need all OBJECTS"
# The command links all object files and Qt5 libraries into the final executable
$(TARGET): $(OBJECTS)
	@echo "Linking $(TARGET)..."
	$(CXX) $(OBJECTS) -o $(TARGET) $(QT5_LIBS)
	@echo "Build complete! Run './$(TARGET)' to start the program."

# =============================================================================
# COMPILATION RULE
# =============================================================================

# Rule to compile .cpp files into .o files
# %.o: %.cpp is a pattern rule that matches any .cpp file
# $< represents the first dependency (the .cpp file)
# $@ represents the target (the .o file)
# This rule compiles each .cpp file with both standard C++ flags and Qt5 flags
%.o: %.cpp
	@echo "Compiling $<..."
	$(CXX) $(CXXFLAGS) $(QT5_CXXFLAGS) -c $< -o $@

# =============================================================================
# UTILITY TARGETS
# =============================================================================

# Clean target - removes all build artifacts
# This is useful when you want to rebuild everything from scratch
# or when you want to clean up after building
clean:
	@echo "Cleaning build artifacts..."
	rm -f $(OBJECTS) $(TARGET)
	@echo "Clean complete!"

# =============================================================================
# DEPENDENCY INSTALLATION TARGETS
# =============================================================================
# These targets help install Qt5 development libraries on different Linux distributions
# Run the appropriate one for your system if Qt5 is not already installed

# Install Qt5 dependencies for Ubuntu/Debian-based systems
# qt5-default: Provides Qt5 as the default Qt version
# qtbase5-dev: Qt5 base development files (headers, libraries)
# qtchooser: Tool to select between different Qt versions
# qt5-qmake: Qt5 build system tool
install-deps:
	@echo "Installing Qt5 dependencies for Ubuntu/Debian..."
	sudo apt-get update
	sudo apt-get install -y qt5-default qtbase5-dev qtchooser qt5-qmake
	@echo "Qt5 dependencies installed successfully!"

# Install Qt5 dependencies for Fedora/RHEL/CentOS-based systems
# qt5-devel: Qt5 development files
# qt5-qtbase-devel: Qt5 base development files
install-deps-fedora:
	@echo "Installing Qt5 dependencies for Fedora/RHEL/CentOS..."
	sudo dnf install -y qt5-devel qt5-qtbase-devel
	@echo "Qt5 dependencies installed successfully!"

# Install Qt5 dependencies for Arch Linux
# qt5-base: Qt5 base development files
install-deps-arch:
	@echo "Installing Qt5 dependencies for Arch Linux..."
	sudo pacman -S qt5-base
	@echo "Qt5 dependencies installed successfully!"

# =============================================================================
# RUN TARGET
# =============================================================================

# Run target - builds the program and then executes it
# This is convenient for testing your program
# The $(TARGET) dependency ensures the program is built before running
run: $(TARGET)
	@echo "Running $(TARGET)..."
	./$(TARGET)

# =============================================================================
# PHONY TARGETS DECLARATION
# =============================================================================
# Phony targets are targets that don't represent actual files
# This tells Make that these targets don't create files with these names
# and should always be executed when requested
.PHONY: all clean install-deps install-deps-fedora install-deps-arch run

# =============================================================================
# HELP TARGET
# =============================================================================

# Help target - displays available make targets and their descriptions
# Useful for new users or when you forget what targets are available
help:
	@echo "=============================================================================="
	@echo "Minimal Qt Window Program - Makefile Help"
	@echo "=============================================================================="
	@echo ""
	@echo "Available targets:"
	@echo ""
	@echo "  all              - Build the complete program (default target)"
	@echo "  clean            - Remove all build artifacts (.o files and executable)"
	@echo "  run              - Build and run the program"
	@echo ""
	@echo "Dependency Installation (choose one for your system):"
	@echo "  install-deps     - Install Qt5 dependencies (Ubuntu/Debian)"
	@echo "  install-deps-fedora - Install Qt5 dependencies (Fedora/RHEL/CentOS)"
	@echo "  install-deps-arch - Install Qt5 dependencies (Arch Linux)"
	@echo ""
	@echo "  help             - Show this help message"
	@echo ""
	@echo "Usage Examples:"
	@echo "  make             # Build the program"
	@echo "  make clean       # Clean build files"
	@echo "  make run         # Build and run"
	@echo "  make install-deps # Install dependencies (Ubuntu/Debian)"
	@echo ""
	@echo "==============================================================================" 