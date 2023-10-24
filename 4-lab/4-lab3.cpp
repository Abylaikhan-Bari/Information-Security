#include <iostream>
#include <fstream>
#include <string>

// Структура для хранения записей таблицы
struct Record {
    std::string property;
    std::string leaseTerm;
    std::string tenantName;
};

// Функция для ввода записи с клавиатуры
Record inputRecord() {
    Record record;
    std::cout << "Введите наименование арендуемого помещения: ";
    std::cin.ignore();
    std::getline(std::cin, record.property);
    std::cout << "Введите срок аренды: ";
    std::cin.ignore();
    std::getline(std::cin, record.leaseTerm);
    std::cout << "Введите наименование арендатора: ";
    std::cin.ignore();
    std::getline(std::cin, record.tenantName);
    return record;
}

// Функция для вывода записи на экран
void printRecord(const Record& record) {
    std::cout << "Наименование арендуемого помещения: " << record.property << std::endl;
    std::cout << "Срок аренды: " << record.leaseTerm << std::endl;
    std::cout << "Наименование арендатора: " << record.tenantName << std::endl;
}

// Функция для сохранения записи в файл
void saveRecordToFile(const Record& record, const std::string& filename) {
    std::ofstream file(filename, std::ios::app); // Открываем файл в режиме добавления
    if (file.is_open()) {
        file << "Наименование арендуемого помещения: " << record.property << '\n';
        file << "Срок аренды: " << record.leaseTerm << '\n';
        file << "Наименование арендатора: " << record.tenantName << '\n';
        file << '\n'; // Разделитель между записями
        file.close();
        std::cout << "Запись сохранена в файле " << filename << std::endl;
    } else {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
    }
}

int main() {
    int choice;
    std::string filename = "table3.txt"; // Имя файла для сохранения данных

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
                        std::getline(file, record.leaseTerm);
                        std::getline(file, record.tenantName);
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
