#include "Utils.h"

// Singleton instance accessor
Utils& Utils::getInstance() {
    static Utils instance; // Guaranteed to be created once and destroyed automatically
    return instance;
}

// Private constructor
Utils::Utils() {
    // You can initialize any member variables here if needed
}


std::string Utils::getResourcePath(const std::string &filename) {
    
    std::string executablePath = std::filesystem::current_path().string();
    return executablePath + "/resources/" + filename;
}