#include <iostream>
#include <string>

// Функция для подсчета глубины вложенности подкаталогов
int countDirectoryDepth(const std::string& directories) {
    int depth = 0;
    size_t pos = directories.find('\\');
    while (pos != std::string::npos) {
        depth++;
        pos = directories.find('\\', pos + 1);
    }
    return depth;
}

int main() {
    std::string fullPath;
    std::string server, volume, directories, fileName;

    std::cout << "Введите имя файла в формате 'сервер:том\\каталог1\\каталог2\\...имя.расширение': ";
    std::cin.ignore();
    std::getline(std::cin, fullPath);

    size_t serverEnd = fullPath.find(':');
    size_t volumeEnd = fullPath.find('\\', serverEnd + 1);
    size_t fileNameStart = fullPath.find_last_of('\\') + 1;

    server = fullPath.substr(0, serverEnd);
    volume = fullPath.substr(serverEnd + 1, volumeEnd - serverEnd - 1);
    directories = fullPath.substr(volumeEnd + 1, fileNameStart - volumeEnd - 1);
    fileName = fullPath.substr(fileNameStart);

    int depth = countDirectoryDepth(directories);

    std::cout << "Глубина вложенности подкаталогов: " << depth << std::endl;

    return 0;
}
