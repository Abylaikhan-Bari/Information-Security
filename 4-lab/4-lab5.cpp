#include <iostream>
#include <fstream>
#include <string>

// Структура для хранения записей таблицы
struct Record {
    std::string productName;
    std::string invoiceNumber;
    int quantity;
};

// Функция для ввода записи с клавиатуры
Record inputRecord() {
    Record record;
    std::cout << "Введите наименование товара: ";
    std::cin.ignore();
    std::getline(std::cin, record.productName);
    std::cout << "Введите номер накладной: ";
    std::cin.ignore();
    std::getline(std::cin, record.invoiceNumber);
    std::cout << "Введите количество: ";
    std::cin >> record.quantity;
    return record;
}

// Функция для вывода записи на экран
void printRecord(const Record& record) {
    std::cout << "Наименование товара: " << record.productName << std::endl;
    std::cout << "Номер накладной: " << record.invoiceNumber << std::endl;
    std::cout << "Количество: " << record.quantity << std::endl;
}

// Функция для сохранения записи в файл
void saveRecordToFile(const Record& record, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << "Наименование товара: " << record.productName << '\n';
        file << "Номер накладной: " << record.invoiceNumber << '\n';
        file << "Количество: " << record.quantity << '\n';
        file << '\n'; // Разделитель между записями
        file.close();
        std::cout << "Запись сохранена в файле " << filename << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

int main() {
    int choice;
    std::string filename = "table.txt"; // Имя файла для сохранения данных

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
                    while (std::getline(file, record.productName)) {
                        std::getline(file, record.invoiceNumber);
                        std::string quantityLine;
                        std::getline(file, quantityLine);
                        record.quantity = std::stoi(quantityLine.substr(quantityLine.find(":") + 2));
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
