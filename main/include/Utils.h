#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <filesystem> // C++17 or later

class Utils {
public:
    // Public method to access the singleton instance
    static Utils& getInstance();

    //          Functions
    std::string getResourcePath(const std::string &filename);

    // Delete copy constructor and assignment operator to enforce singleton behavior
    Utils(const Utils&) = delete;
    Utils& operator=(const Utils&) = delete;

private:
    // Private constructor to prevent instantiation
    Utils();
};

#endif