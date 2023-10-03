#include <iostream>
#include <string>
#include <vector>

struct PortalInfo {
    std::string portalName;
    std::string address;
};

int main() {
    std::vector<PortalInfo> portals;

    std::cout << "Enter 5 pairs of Internet portal names and addresses:\n";

    for (int i = 0; i < 5; ++i) {
        PortalInfo portal;
        std::string input;

        std::cin.ignore(); // Clear any newline left in the input buffer.

        // Read the Internet portal name and address as a single string.
        std::getline(std::cin, input);

        // Parse the input into portal name and address.
        size_t commaPos = input.find(",");
        
        if (commaPos != std::string::npos) {
            portal.address = input.substr(0, commaPos);
            portal.portalName = input.substr(commaPos + 1);
        } else {
            std::cout << "Invalid input format. Please enter pairs in the format 'Address, Internet Portal Name'.\n";
            --i; // Decrement i to re-enter the pair.
            continue;
        }

        portals.push_back(portal);
    }

    std::cout << "\nSerial Number\tAddress\tInternet Portal Name\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << i + 1 << "\t\t" << portals[i].address << "\t" << portals[i].portalName << "\n";
    }

    return 0;
}
