#include <iostream>
#include <string>

int main() {
    std::string dates[12];

    std::cout << "Enter 12 dates in the format dd. mm. yy:\n";

    for (int i = 0; i < 12; ++i) {
        std::cin >> dates[i];

        // Check if the input has the correct length and format.
        if (dates[i].length() != 8 || dates[i][2] != '.' || dates[i][5] != '.') {
            std::cout << "Invalid date format. Please enter dates in the format dd. mm. yy.\n";
            --i; // Decrement i to re-enter the date.
        }
    }

    std::cout << "\nDate (dd.mm.yy)\tDate (dd.mm.yy)\tDate (dd.mm.yy)\n";
    for (int i = 0; i < 12; i += 3) {
        for (int j = 0; j < 3; ++j) {
            if (i + j < 12) {
                std::cout << dates[i + j] << "\t\t";
            } else {
                std::cout << "\t\t"; // Empty space
            }
        }
        std::cout << "\n";
    }

    return 0;
}
