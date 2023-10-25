#include <iostream>
#include <string>

// Function to split the string into server, volume, directories, and file name
void splitPath(const std::string& fullPath, std::string& server, std::string& volume, std::string& directories, std::string& fileName) {
    size_t serverEnd = fullPath.find(':');
    size_t volumeEnd = fullPath.find('\\', serverEnd + 1);
    size_t fileNameStart = fullPath.find_last_of('\\') + 1;

    server = fullPath.substr(0, serverEnd);
    volume = fullPath.substr(serverEnd + 1, volumeEnd - serverEnd - 1);
    directories = fullPath.substr(volumeEnd + 1, fileNameStart - volumeEnd - 1);
    fileName = fullPath.substr(fileNameStart);
}

int main() {
    std::string fullPath;
    std::string server, volume, directories, fileName;

    std::cout << "Enter the file name in the format 'server:volume\\directory1\\directory2\\...file.extension': ";
    std::cin.ignore();
    std::getline(std::cin, fullPath);

    splitPath(fullPath, server, volume, directories, fileName);

    std::cout << "Server: " << server << std::endl;
    std::cout << "Volume: " << volume << std::endl;
    std::cout << "Directories: " << directories << std::endl;
    std::cout << "File Name: " << fileName << std::endl;

    return 0;
}
