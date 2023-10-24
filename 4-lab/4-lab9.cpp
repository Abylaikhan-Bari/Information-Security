#include <iostream>
#include <fstream>
#include <string>

// Структура для хранения записей таблицы
struct Record {
    std::string propertyName;
    int leaseTerm;
    double monthlyRent;
};

// Функция для ввода записи с клавиатуры
Record inputRecord() {
    Record record;
    std::cout << "Введите наименование арендуемого помещения: ";
    std::cin.ignore();
    std::getline(std::cin, record.propertyName);
    std::cout << "Введите срок аренды (в месяцах): ";
    std::cin >> record.leaseTerm;
    std::cout << "Введите стоимость аренды в месяц: ";
    std::cin >> record.monthlyRent;
    return record;
}

// Функция для вывода записи на экран
void printRecord(const Record& record) {
    std::cout << "Наименование арендуемого помещения: " << record.propertyName << std::endl;
    std::cout << "Срок аренды (в месяцах): " << record.leaseTerm << std::endl;
    std::cout << "Стоимость аренды в месяц: " << record.monthlyRent << std::endl;
}

// Функция для сохранения записи в файл
void saveRecordToFile(const Record& record, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << "Наименование арендуемого помещения: " << record.propertyName << '\n';
        file << "Срок аренды (в месяцах): " << record.leaseTerm << '\n';
        file << "Стоимость аренды в месяц: " << record.monthlyRent << '\n';
        file << '\n'; // Разделитель между записями
        file.close();
        std::cout << "Запись сохранена в файле " << filename << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

int main() {
    int choice;
    std::string filename = "table9.txt"; // Имя файла для сохранения данных

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
                    while (std::getline(file, record.propertyName)) {
                        std::string termLine;
                        std::getline(file, termLine);
                        record.leaseTerm = std::stoi(termLine.substr(termLine.find(":") + 2));
                        std::string rentLine;
                        std::getline(file, rentLine);
                        record.monthlyRent = std::stod(rentLine.substr(rentLine.find(":") + 2));
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
