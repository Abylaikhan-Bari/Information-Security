#include <iostream>
#include <string>

// Функция для разбиения строки на сервер, том и каталоги
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

    std::cout << "Введите имя файла в формате 'сервер:том\\каталог1\\каталог2\\...имя.расширение': ";
    std::cin.ignore();
    std::getline(std::cin, fullPath);

    splitPath(fullPath, server, volume, directories, fileName);

    std::cout << "Сервер: " << server << std::endl;
    std::cout << "Том: " << volume << std::endl;
    std::cout << "Каталоги: " << directories << std::endl;
    std::cout << "Имя файла: " << fileName << std::endl;

    return 0;
}
