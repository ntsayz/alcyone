#!/bin/bash

# Define the build directory
BUILD_DIR="build"

# Check if the build directory exists; if not, create it
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Run CMake to configure the project
cmake -S . -B "$BUILD_DIR"

# Build the project
cmake --build "$BUILD_DIR"

# Check if the build was successful
if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

# Run the executable
EXECUTABLE="$BUILD_DIR/ProjectAlcyone"
if [ -f "$EXECUTABLE" ]; then
    echo "Running the program..."
    "$EXECUTABLE"
else
    echo "Executable not found! Check your build."
    exit 1
fi