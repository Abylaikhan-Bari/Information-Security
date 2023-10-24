#include <iostream>
#include <fstream>
#include <string>

// Структура для хранения записей таблицы
struct Record {
    std::string property;
    double cost;
    std::string owner;
};

// Функция для ввода записи с клавиатуры
Record inputRecord() {
    Record record;
    std::cout << "Введите объект недвижимости: ";
    std::cin.ignore();
    std::getline(std::cin, record.property);
    std::cout << "Введите стоимость: ";
    std::cin >> record.cost;
    std::cin.ignore();
    std::cout << "Введите владельца: ";
    std::getline(std::cin, record.owner);
    return record;
}

// Функция для вывода записи на экран
void printRecord(const Record& record) {
    std::cout << "Объект недвижимости: " << record.property << std::endl;
    std::cout << "Стоимость: " << record.cost << std::endl;
    std::cout << "Владелец: " << record.owner << std::endl;
}

// Функция для сохранения записи в файл
void saveRecordToFile(const Record& record, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << "Объект недвижимости: " << record.property << '\n';
        file << "Стоимость: " << record.cost << '\n';
        file << "Владелец: " << record.owner << '\n';
        file << '\n'; // Разделитель между записями
        file.close();
        std::cout << "Запись сохранена в файле " << filename << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

int main() {
    int choice;
    std::string filename = "table4.txt"; // Имя файла для сохранения данных

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
                        std::string costLine;
                        std::getline(file, costLine);
                        record.cost = std::stod(costLine.substr(costLine.find(":") + 2));
                        std::getline(file, record.owner);
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
