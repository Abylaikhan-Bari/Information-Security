#include <iostream>
#include <fstream>
#include <string>

// Структура для хранения записей таблицы
struct Record {
    std::string employeeName;
    double monthlySalary;
    double bonus;
};

// Функция для ввода записи с клавиатуры
Record inputRecord() {
    Record record;
    std::cout << "Введите Ф.И.О. работника: ";
    std::cin.ignore();
    std::getline(std::cin, record.employeeName);
    std::cout << "Введите ставку месячной оплаты: ";
    std::cin >> record.monthlySalary;
    std::cout << "Введите премию: ";
    std::cin >> record.bonus;
    return record;
}

// Функция для вывода записи на экран
void printRecord(const Record& record) {
    std::cout << "Ф.И.О. работника: " << record.employeeName << std::endl;
    std::cout << "Ставка месячной оплаты: " << record.monthlySalary << std::endl;
    std::cout << "Премия: " << record.bonus << std::endl;
}

// Функция для сохранения записи в файл
void saveRecordToFile(const Record& record, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << "Ф.И.О. работника: " << record.employeeName << '\n';
        file << "Ставка месячной оплаты: " << record.monthlySalary << '\n';
        file << "Премия: " << record.bonus << '\n';
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
                    while (std::getline(file, record.employeeName)) {
                        std::string salaryLine;
                        std::getline(file, salaryLine);
                        record.monthlySalary = std::stod(salaryLine.substr(salaryLine.find(":") + 2));
                        std::string bonusLine;
                        std::getline(file, bonusLine);
                        record.bonus = std::stod(bonusLine.substr(bonusLine.find(":") + 2));
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
