#include <iostream>
#include <string>
#include <vector>

struct PhoneNumber {
    std::string number;
};

int main() {
    std::vector<PhoneNumber> phoneNumbers;

    std::cout << "Enter 10 phone numbers (XXXXXXXXXX):\n";

    for (int i = 0; i < 10; ++i) {
        PhoneNumber phoneNumber;
        std::string input;

        std::cin >> input;

        // Check if the input has the correct length (10 digits).
        if (input.length() != 10) {
            std::cout << "Invalid phone number format. Please enter 10-digit phone numbers (XXXXXXXXXX).\n";
            --i; // Decrement i to re-enter the phone number.
            continue;
        }

        phoneNumber.number = input;
        phoneNumbers.push_back(phoneNumber);
    }

    std::cout << "\nSequence Number\tNetwork Number\tOn-Net Phone Number\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << i + 1 << "\t\t" << phoneNumbers[i].number.substr(0, 3) << "\t\t" << phoneNumbers[i].number.substr(3) << "\n";
    }

    return 0;
}
