#include <iostream>
#include <fstream>
#include <string>

// Структура для хранения записей таблицы
struct Record {
    std::string property;
    std::string owner;
    std::string address;
};

// Функция для ввода записи с клавиатуры
Record inputRecord() {
    Record record;
    std::cout << "Введите объект недвижимости: ";
    std::cin.ignore();
    std::getline(std::cin, record.property);
    std::cout << "Введите владельца: ";
    std::cin.ignore();
    std::getline(std::cin, record.owner);
    std::cout << "Введите адрес: ";
    std::cin.ignore();
    std::getline(std::cin, record.address);
    return record;
}

// Функция для вывода записи на экран
void printRecord(const Record& record) {
    std::cout << "Объект недвижимости: " << record.property << std::endl;
    std::cout << "Владелец: " << record.owner << std::endl;
    std::cout << "Адрес: " << record.address << std::endl;
}

// Функция для сохранения записи в файл
void saveRecordToFile(const Record& record, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << "Объект недвижимости: " << record.property << '\n';
        file << "Владелец: " << record.owner << '\n';
        file << "Адрес: " << record.address << '\n';
        file << '\n'; // Разделитель между записями
        file.close();
        std::cout << "Запись сохранена в файле " << filename << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

int main() {
    int choice;
    std::string filename = "table10.txt"; // Имя файла для сохранения данных

    while (true) {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Добавить запись" << std::endl;
        std::cout << "2. Вывести все записи" << std::endl;
        std::cout << "3. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Record record = inputRecord();
                saveRecordToFile(record, filename);
                break;
            }
            case 2: {
                std::ifstream file(filename);
                if (file.is_open()) {
                    Record record;
                    while (std::getline(file, record.property)) {
                        std::getline(file, record.owner);
                        std::getline(file, record.address);
                        std::string emptyLine;
                        std::getline(file, emptyLine); // Пропускаем пустую строку
                        printRecord(record);
                    }
                    file.close();
                } else {
                    std::cerr << "Не удалось открыть файл для чтения." << std::endl;
                }
                break;
            }
            case 3:
                return 0;
            default:
                std::cout << "Некорректный выбор. Попробуйте еще раз." << std::endl;
        }
    }

    return 0;
}
