#include <iostream>
#include <vector>
#include <cctype>

int main() {
    std::vector<char> letters;
    std::vector<int> numbers;

    std::cout << "Enter 20 numbers and letters:\n";

    for (int i = 0; i < 20; ++i) {
        char input;
        std::cin >> input;

        if (isdigit(input)) {
            numbers.push_back(input - '0'); // Convert char to int
        } else if (isalpha(input)) {
            letters.push_back(input);
        } else {
            std::cout << "Invalid input. Please enter a letter or a number.\n";
            --i; // Decrement i to re-enter the character.
        }
    }

    std::cout << "\nLetters\tNumbers\n";
    for (int i = 0; i < 20; ++i) {
        if (i < letters.size()) {
            std::cout << letters[i] << "\t";
        } else {
            std::cout << "\t"; // Empty space
        }

        if (i < numbers.size()) {
            std::cout << numbers[i];
        }

        std::cout << "\n";
    }

    return 0;
}
