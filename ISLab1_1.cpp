#include <iostream>
#include <vector>

int main() {
    std::vector<int> twoDigitNumbers;
    std::vector<int> threeDigitNumbers;

    std::cout << "Enter 20 two- and three-digit numbers:\n";

    for (int i = 0; i < 20; ++i) {
        int number;
        std::cin >> number;

        if (number >= 10 && number <= 99) {
            twoDigitNumbers.push_back(number);
        }
        else if (number >= 100 && number <= 999) {
            threeDigitNumbers.push_back(number);
        }
        else {
            std::cout << "Invalid number. Please enter a two- or three-digit number.\n";
            --i; // Decrement i to re-enter the number.
        }
    }

    std::cout << "\nTwo-Digit Numbers\tThree-Digit Numbers\n";
    for (int i = 0; i < 20; ++i) {
        if (i < twoDigitNumbers.size()) {
            std::cout << twoDigitNumbers[i] << "\t\t";
        }
        else {
            std::cout << "\t\t"; // Empty space
        }

        if (i < threeDigitNumbers.size()) {
            std::cout << threeDigitNumbers[i];
        }

        std::cout << "\n";
    }

    return 0;
}
