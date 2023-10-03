#include <iostream>
#include <vector>
#include <string>

struct StudyGroup {
    std::string groupName;
    std::string lastName;
};

int main() {
    std::vector<StudyGroup> studyGroups;

    std::cout << "Enter 10 names and numbers of study groups:\n";

    for (int i = 1; i <= 10; ++i) {
        StudyGroup group;
        group.groupName = "Group " + std::to_string(i);
        
        std::cout << "Enter the last name for " << group.groupName << ": ";
        std::cin >> group.lastName;

        studyGroups.push_back(group);
    }

    std::cout << "\nSerial Number\tGroup Name\tLast Name\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << i + 1 << "\t\t" << studyGroups[i].groupName << "\t\t" << studyGroups[i].lastName << "\n";
    }

    return 0;
}
