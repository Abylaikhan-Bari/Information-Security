#include <iostream>
#include <cmath>

// Функция для вычисления значения функции
double CalculateFunction(int x1, int x2, int x3, int x4) {
    // Вычисление значения функции по заданной формуле
    double numerator = 0.3 * pow(x1, 5) + 0.4 * pow(x2, 4);
    double denominator = 12 * pow(x3, 3) - 30 * pow(x4, 4);

    if (denominator != 0) {
        double result = sqrt(numerator / denominator);
        return result;
    } else {
        // Обработка случая деления на ноль
        std::cerr << "Error: Division by zero." << std::endl;
        return 0; // Можно возвращать какое-то значение по умолчанию
    }
}

int main() {
    int x1, x2, x3, x4;

    // Ввод значений x1, x2, x3 и x4 (целые числа)
    std::cout << "Enter x1: ";
    std::cin >> x1;
    std::cout << "Enter x2: ";
    std::cin >> x2;
    std::cout << "Enter x3: ";
    std::cin >> x3;
    std::cout << "Enter x4: ";
    std::cin >> x4;

    // Вычисление значения функции
    double result = CalculateFunction(x1, x2, x3, x4);

    // Вывод результата
    std::cout << "Y = " << result << std::endl;

    return 0;
}
