#include <iostream>
#include <cmath>

// Функция для вычисления значения функции
double CalculateFunction(int x1, int x2, int x3, int x4) {
    // Вычисление значения функции по заданной формуле
    double term1 = sin(log10(x1 + x2) / log10(5));
    double term2 = log10(pow(x3, x4));

    double result = term1 + term2;

    return result;
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
