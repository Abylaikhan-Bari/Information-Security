#include <iostream>
#include <vector>

int main() {
    std::vector<int> evenNumbers;
    std::vector<int> oddNumbers;

    std::cout << "Enter 20 even and odd numbers:\n";

    for (int i = 0; i < 20; ++i) {
        int number;
        std::cin >> number;

        if (number % 2 == 0) {
            evenNumbers.push_back(number);
        } else {
            oddNumbers.push_back(number);
        }
    }

    std::cout << "\nEven Numbers\tOdd Numbers\n";
    for (int i = 0; i < 20; ++i) {
        if (i < evenNumbers.size()) {
            std::cout << evenNumbers[i] << "\t\t";
        } else {
            std::cout << "\t\t"; // Empty space
        }

        if (i < oddNumbers.size()) {
            std::cout << oddNumbers[i];
        }

        std::cout << "\n";
    }

    return 0;
}
