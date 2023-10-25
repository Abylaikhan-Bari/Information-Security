#include <iostream>
#include <string>

// Function to determine if two files are in the same subdirectories
bool areInSameSubdirectories(const std::string& path1, const std::string& path2) {
    size_t lastBackslash1 = path1.find_last_of('\\');
    size_t lastBackslash2 = path2.find_last_of('\\');

    if (lastBackslash1 == std::string::npos || lastBackslash2 == std::string::npos) {
        // One of the paths doesn't contain directories
        return false;
    }

    std::string subdirectories1 = path1.substr(0, lastBackslash1);
    std::string subdirectories2 = path2.substr(0, lastBackslash2);

    return subdirectories1 == subdirectories2;
}

int main() {
    std::string fullPath1, fullPath2;

    std::cout << "Enter the first file name in the format 'server:volume\\directory1\\directory2\\...file.extension': ";
    std::cin.ignore();
    std::getline(std::cin, fullPath1);

    std::cout << "Enter the second file name in the format 'server:volume\\directory1\\directory2\\...file.extension': ";
    std::getline(std::cin, fullPath2);

    if (areInSameSubdirectories(fullPath1, fullPath2)) {
        std::cout << "Both files are in the same subdirectories." << std::endl;
    } else {
        std::cout << "The files are in different subdirectories." << std::endl;
    }

    return 0;
}
