#include <iostream>
#include <cmath>

// Функция для вычисления значения функции
double CalculateFunction(double x1, double x2, double x3, double x4) {
    // Вычисление значения функции по заданной формуле
    double numerator = 3.4 * pow(x2, 4);
    double denominator = 12 * pow(x3, 3) - 30 * pow(x4, 4);
    double term1 = numerator / denominator;
    double term2 = 0.53 * pow(x1, 5);
    double result = term1 + term2;

    return result;
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
