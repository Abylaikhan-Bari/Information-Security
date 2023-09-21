#include <iostream>
#include <vector>

int main() {
    std::vector<int> integers;
    std::vector<double> fractionals;

    std::cout << "Enter 20 whole and fractional numbers:\n";

    for (int i = 0; i < 20; ++i) {
        double number;
        std::cin >> number;

        int integerPart = static_cast<int>(number); // Extract the integer part
        double fractionalPart = number - integerPart; // Extract the fractional part

        integers.push_back(integerPart);
        fractionals.push_back(fractionalPart);
    }

    std::cout << "\nInteger Numbers\tFractional Numbers\n";
    for (int i = 0; i < 20; ++i) {
        std::cout << integers[i] << "\t\t" << fractionals[i] << "\n";
    }

    return 0;
}
