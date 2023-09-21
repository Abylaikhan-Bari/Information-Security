#include <iostream>
#include <string>
#include <vector>

struct FullName {
    std::string firstName;
    std::string middleName;
    std::string lastName;
};

int main() {
    std::vector<FullName> names;

    std::cout << "Enter 6 full names (surname, first name, patronymic):\n";

    for (int i = 0; i < 6; ++i) {
        FullName fullName;
        std::string input;

        std::cin.ignore(); // Clear any newline left in the input buffer.
        
        // Read the full name as a single string.
        std::getline(std::cin, input);

        // Parse the full name into first name, middle name, and last name.
        size_t firstComma = input.find(",");
        size_t secondComma = input.find(",", firstComma + 1);

        if (firstComma != std::string::npos && secondComma != std::string::npos) {
            fullName.lastName = input.substr(0, firstComma);
            fullName.firstName = input.substr(firstComma + 1, secondComma - firstComma - 1);
            fullName.middleName = input.substr(secondComma + 1);
        } else {
            std::cout << "Invalid name format. Please enter names in the format 'Last Name, First Name, Patronymic'.\n";
            --i; // Decrement i to re-enter the name.
            continue;
        }

        names.push_back(fullName);
    }

    std::cout << "\nFirst Name\tMiddle Name\tLast Name\n";
    for (const FullName& fullName : names) {
        std::cout << fullName.firstName << "\t\t" << fullName.middleName << "\t\t" << fullName.lastName << "\n";
    }

    return 0;
}
