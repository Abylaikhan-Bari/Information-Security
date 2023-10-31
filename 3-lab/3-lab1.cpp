#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {
    int F1_bits, F2_bits, F3_bits, F4_bits;

    // Ввод разрядностей полей с консоли
    cout << "Введите разрядность поля F1: ";
    cin >> F1_bits;

    cout << "Введите разрядность поля F2: ";
    cin >> F2_bits;

    cout << "Введите разрядность поля F3: ";
    cin >> F3_bits;

    cout << "Введите разрядность поля F4: ";
    cin >> F4_bits;

    if (F1_bits + F2_bits + F3_bits + F4_bits != 32) {
        cerr << "Сумма разрядностей полей не равна 32. Проверьте введенные значения.\n";
        return 1;
    }

    //4F1A3E8D Запрос ввода пакета данных в виде 16-ричной символьной комбинации
    string input;
    cout << "Введите 32-разрядный пакет данных (16-ричная комбинация): ";
    cin >> input;

    // Проверка на правильную длину входных данных
    if (input.length() != 8) {
        cerr << "Неверная длина входных данных. Введите 8 символов.\n";
        return 1;
    }

    // Преобразование входной строки в целое число
    unsigned int packet = stoi(input, 0, 16);

    // Создание масок для каждого поля
    unsigned int F1_mask = (1 << F1_bits) - 1;
    unsigned int F2_mask = (1 << F2_bits) - 1;
    unsigned int F3_mask = (1 << F3_bits) - 1;
    unsigned int F4_mask = (1 << F4_bits) - 1;

    // Выделение полей
    int F0 = (packet >> (F1_bits + F2_bits + F3_bits + F4_bits)) & 0x1;
    int F1 = (packet >> (F2_bits + F3_bits + F4_bits)) & F1_mask;
    int F2 = (packet >> (F3_bits + F4_bits)) & 0x1;
    int F3 = (packet >> F4_bits) & F3_mask;
    int F4 = packet & F4_mask;

    // Вычисление контрольной суммы
    int checksum = (F0 + F1 + F2 + F3 + F4) % 31;

    // Вывод результатов на экран
    cout << "F0: " << F0 << endl;
    cout << "F1: " << bitset<32>(F1) << endl;
    cout << "F2: " << F2 << endl;
    cout << "F3: " << bitset<32>(F3) << endl;
    cout << "F4: " << bitset<32>(F4) << endl;
    cout << "Контрольная сумма: " << checksum << endl;

    return 0;
}
