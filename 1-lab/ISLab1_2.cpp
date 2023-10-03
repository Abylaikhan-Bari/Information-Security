#include <iostream>
#include <cctype>
#include <vector>

int main() {
    std::vector<char> lowercaseChars;
    std::vector<char> uppercaseChars;

    std::cout << "Enter 20 characters:\n";

    for (int i = 0; i < 20; ++i) {
        char character;
        std::cin >> character;

        if (isalpha(character)) {
            if (islower(character)) {
                lowercaseChars.push_back(character);
            } else if (isupper(character)) {
                uppercaseChars.push_back(character);
            }
        } else {
            std::cout << "Invalid character. Please enter a letter.\n";
            --i; // Decrement i to re-enter the character.
        }
    }

    std::cout << "\nLowercase Characters\tUppercase Characters\n";
    for (int i = 0; i < 20; ++i) {
        if (i < lowercaseChars.size()) {
            std::cout << lowercaseChars[i] << "\t\t";
        } else {
            std::cout << "\t\t"; // Empty space
        }

        if (i < uppercaseChars.size()) {
            std::cout << uppercaseChars[i];
        }

        std::cout << "\n";
    }

    return 0;
}
