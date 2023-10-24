#include <iostream>
#include <fstream>
#include <string>

// Структура для хранения записей таблицы
struct Record {
    std::string employeeName;
    std::string hireDate;
    std::string orderNumber;
};

// Функция для ввода записи с клавиатуры
Record inputRecord() {
    Record record;
    std::cout << "Введите Ф.И.О. работника: ";
    std::cin.ignore();
    std::getline(std::cin, record.employeeName);
    std::cout << "Введите дату приема на работу: ";
    std::cin.ignore();
    std::getline(std::cin, record.hireDate);
    std::cout << "Введите номер приказа о приеме на работу: ";
    std::cin.ignore();
    std::getline(std::cin, record.orderNumber);
    return record;
}

// Функция для вывода записи на экран
void printRecord(const Record& record) {
    std::cout << "Ф.И.О. работника: " << record.employeeName << std::endl;
    std::cout << "Дата приема на работу: " << record.hireDate << std::endl;
    std::cout << "Номер приказа о приеме на работу: " << record.orderNumber << std::endl;
}

// Функция для сохранения записи в файл
void saveRecordToFile(const Record& record, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << "Ф.И.О. работника: " << record.employeeName << '\n';
        file << "Дата приема на работу: " << record.hireDate << '\n';
        file << "Номер приказа о приеме на работу: " << record.orderNumber << '\n';
        file << '\n'; // Разделитель между записями
        file.close();
        std::cout << "Запись сохранена в файле " << filename << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

int main() {
    int choice;
    std::string filename = "table2.txt"; // Имя файла для сохранения данных

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
                    while (std::getline(file, record.employeeName)) {
                        std::getline(file, record.hireDate);
                        std::getline(file, record.orderNumber);
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
