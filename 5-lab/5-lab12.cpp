#include <iostream>
#include <string>

// Function to determine if two files are in the same subdirectories
bool areInSameSubdirectories(const std::string& url1, const std::string& url2) {
    size_t serverEnd1 = url1.find("://");
    size_t serverEnd2 = url2.find("://");
    size_t lastBackslash1 = url1.find_last_of('\\');
    size_t lastBackslash2 = url2.find_last_of('\\');

    if (serverEnd1 == std::string::npos || serverEnd2 == std::string::npos ||
        lastBackslash1 == std::string::npos || lastBackslash2 == std::string::npos) {
        // One of the paths does not contain directories
        return false;
    }

    std::string subdirectories1 = url1.substr(serverEnd1 + 3, lastBackslash1 - serverEnd1 - 3);
    std::string subdirectories2 = url2.substr(serverEnd2 + 3, lastBackslash2 - serverEnd2 - 3);

    return subdirectories1 == subdirectories2;
}

int main() {
    std::string url1, url2;

    std::cout << "Enter the first internet address of the file: ";
    std::cin.ignore();
    std::getline(std::cin, url1);

    std::cout << "Enter the second internet address of the file: ";
    std::getline(std::cin, url2);

    if (areInSameSubdirectories(url1, url2)) {
        std::cout << "Both files are in the same subdirectories." << std::endl;
    } else {
        std::cout << "The files are in different subdirectories." << std::endl;
    }

    return 0;
}
