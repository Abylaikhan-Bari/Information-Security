#include <iostream>
#include <string>

// Function to split a URL into server, directories, and file name
void splitURL(const std::string& url, std::string& server, std::string& directories, std::string& fileName) {
    size_t protocolEnd = url.find("://");
    size_t serverEnd = url.find('/', protocolEnd + 3);

    server = url.substr(protocolEnd + 3, serverEnd - protocolEnd - 3);
    directories = url.substr(serverEnd + 1, url.find_last_of('/') - serverEnd);
    fileName = url.substr(url.find_last_of('/') + 1);
}

int main() {
    std::string url;
    std::string server, directories, fileName;

    std::cout << "Enter the internet address of the file in the format 'http://www.server.com\\directory1\\directory2\\...file.extension': ";
    std::cin.ignore();
    std::getline(std::cin, url);

    splitURL(url, server, directories, fileName);

    std::cout << "Server: " << server << std::endl;
    std::cout << "Directories: " << directories << std::endl;
    std::cout << "File Name: " << fileName << std::endl;

    return 0;
}
