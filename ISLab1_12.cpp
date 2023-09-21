#include <iostream>
#include <string>
#include <vector>

struct CityInfo {
    std::string cityName;
    std::string areaCode;
};

int main() {
    std::vector<CityInfo> cities;

    std::cout << "Enter 5 pairs of city names and area codes:\n";

    for (int i = 0; i < 5; ++i) {
        CityInfo city;
        std::string input;

        std::cin.ignore(); // Clear any newline left in the input buffer.
        
        // Read the city name and area code as a single string.
        std::getline(std::cin, input);

        // Parse the input into city name and area code.
        size_t commaPos = input.find(",");
        
        if (commaPos != std::string::npos) {
            city.areaCode = input.substr(0, commaPos);
            city.cityName = input.substr(commaPos + 1);
        } else {
            std::cout << "Invalid input format. Please enter pairs in the format 'Area Code, City Name'.\n";
            --i; // Decrement i to re-enter the pair.
            continue;
        }

        cities.push_back(city);
    }

    std::cout << "\nSerial Number\tArea Code\tCity Name\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 << "\t\t" << cities[i].areaCode << "\t\t" << cities[i].cityName << "\n";
    }

    return 0;
}
