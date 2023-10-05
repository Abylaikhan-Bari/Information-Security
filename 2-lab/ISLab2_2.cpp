#include <iostream>
#include <cmath>

// Функция для вычисления значения функции
double CalculateFunction(double x1, double x2, double x3, double x4) {
    // Вычисление значения функции по заданной формуле
    double numerator = tan(x1 - 90.0);
    double denominator = tan(x3 - 190.0);

    if (denominator != 0) {
        double result = numerator / denominator;
        return result;
    } else {
        // Обработка случая деления на ноль
        std::cerr << "Error: Division by zero." << std::endl;
        return 0; // Можно возвращать какое-то значение по умолчанию
    }
}

int main() {
    double x1, x2, x3, x4;

    // Ввод значений x1, x2, x3 и x4
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
