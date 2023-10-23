#include <iostream>
#include <fstream>
#include <string>

// Структура для хранения записей таблицы
struct Record {
    std::string serviceName;
    double contractPrice;
    bool completionStatus;
};

// Функция для ввода записи с клавиатуры
Record inputRecord() {
    Record record;
    std::cout << "Введите наименование услуги: ";
    std::cin.ignore();
    std::getline(std::cin, record.serviceName);
    std::cout << "Введите договорную цену: ";
    std::cin >> record.contractPrice;
    std::cout << "Введите отметку о выполнении (1 - выполнено, 0 - не выполнено): ";
    std::cin >> record.completionStatus;
    return record;
}

// Функция для вывода записи на экран
void printRecord(const Record& record) {
    std::cout << "Наименование услуги: " << record.serviceName << std::endl;
    std::cout << "Договорная цена: " << record.contractPrice << std::endl;
    std::cout << "Отметка о выполнении: " << (record.completionStatus ? "Выполнено" : "Не выполнено") << std::endl;
}

// Функция для сохранения записи в файл
void saveRecordToFile(const Record& record, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << "Наименование услуги: " << record.serviceName << '\n';
        file << "Договорная цена: " << record.contractPrice << '\n';
        file << "Отметка о выполнении: " << (record.completionStatus ? "Выполнено" : "Не выполнено") << '\n';
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
                    while (std::getline(file, record.serviceName)) {
                        std::string priceLine;
                        std::getline(file, priceLine);
                        record.contractPrice = std::stod(priceLine.substr(priceLine.find(":") + 2));
                        std::string statusLine;
                        std::getline(file, statusLine);
                        record.completionStatus = (statusLine.find("Выполнено") != std::string::npos);
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
