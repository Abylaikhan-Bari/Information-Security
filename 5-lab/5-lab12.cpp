#include <iostream>
#include <string>

// Функция для определения, находятся ли два файла в одноименных подкаталогах
bool areInSameSubdirectories(const std::string& url1, const std::string& url2) {
    size_t serverEnd1 = url1.find("://");
    size_t serverEnd2 = url2.find("://");
    size_t lastBackslash1 = url1.find_last_of('\\');
    size_t lastBackslash2 = url2.find_last_of('\\');

    if (serverEnd1 == std::string::npos || serverEnd2 == std::string::npos ||
        lastBackslash1 == std::string::npos || lastBackslash2 == std::string::npos) {
        // Один из путей не содержит каталогов
        return false;
    }

    std::string subdirectories1 = url1.substr(serverEnd1 + 3, lastBackslash1 - serverEnd1 - 3);
    std::string subdirectories2 = url2.substr(serverEnd2 + 3, lastBackslash2 - serverEnd2 - 3);

    return subdirectories1 == subdirectories2;
}

int main() {
    std::string url1, url2;

    std::cout << "Введите первый интернет-адрес файла: ";
    std::cin.ignore();
    std::getline(std::cin, url1);

    std::cout << "Введите второй интернет-адрес файла: ";
    std::getline(std::cin, url2);

    if (areInSameSubdirectories(url1, url2)) {
        std::cout << "Оба файла находятся в одноименных подкаталогах." << std::endl;
    } else {
        std::cout << "Файлы находятся в разных подкаталогах." << std::endl;
    }

    return 0;
}
