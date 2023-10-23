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
    std::string url;
    std::string directories;

    std::cout << "Введите интернет-адрес файла в формате 'http://www.сервер.ги\\каталог1\\каталог2\\...имя.расширение': ";
    std::cin.ignore();
    std::getline(std::cin, url);

    size_t serverEnd = url.find("://");
    size_t serverStart = url.find('.', serverEnd + 3) + 1;
    size_t fileNameStart = url.find_last_of('\\') + 1;

    directories = url.substr(serverStart, url.find_last_of('\\') - serverStart);

    int depth = countDirectoryDepth(directories);

    std::cout << "Глубина вложенности подкаталогов: " << depth << std::endl;

    return 0;
}
