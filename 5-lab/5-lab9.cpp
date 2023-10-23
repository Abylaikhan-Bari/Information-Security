#include <iostream>
#include <string>

// Функция для определения, находятся ли два файла в одноименных подкаталогах
bool areInSameSubdirectories(const std::string& path1, const std::string& path2) {
    size_t lastBackslash1 = path1.find_last_of('\\');
    size_t lastBackslash2 = path2.find_last_of('\\');

    if (lastBackslash1 == std::string::npos || lastBackslash2 == std::string::npos) {
        // Один из путей не содержит каталогов
        return false;
    }

    std::string subdirectories1 = path1.substr(0, lastBackslash1);
    std::string subdirectories2 = path2.substr(0, lastBackslash2);

    return subdirectories1 == subdirectories2;
}

int main() {
    std::string fullPath1, fullPath2;

    std::cout << "Введите первое имя файла в формате 'сервер:том\\каталог1\\каталог2\\...имя.расширение': ";
    std::cin.ignore();
    std::getline(std::cin, fullPath1);

    std::cout << "Введите второе имя файла в формате 'сервер:том\\каталог1\\каталог2\\...имя.расширение': ";
    std::getline(std::cin, fullPath2);

    if (areInSameSubdirectories(fullPath1, fullPath2)) {
        std::cout << "Оба файла находятся в одноименных подкаталогах." << std::endl;
    } else {
        std::cout << "Файлы находятся в разных подкаталогах." << std::endl;
    }

    return 0;
}
