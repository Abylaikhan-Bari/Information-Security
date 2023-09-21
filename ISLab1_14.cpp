#include <iostream>
#include <string>
#include <vector>

struct CourseInfo {
    std::string courseName;
    int grade;
};

std::string getAssessment(int grade) {
    if (grade >= 90) {
        return "excellent";
    } else if (grade >= 70) {
        return "good";
    } else {
        return "satisfactory";
    }
}

int main() {
    std::vector<CourseInfo> courses;

    std::cout << "Enter 6 names of training courses and their grades (numerical form):\n";

    for (int i = 0; i < 6; ++i) {
        CourseInfo course;
        std::string input;

        std::cin.ignore(); // Clear any newline left in the input buffer.

        // Read the course name and grade as a single string.
        std::getline(std::cin, input);

        // Parse the input into course name and grade.
        size_t spacePos = input.find_last_of(" ");
        
        if (spacePos != std::string::npos) {
            course.grade = std::stoi(input.substr(spacePos + 1));
            course.courseName = input.substr(0, spacePos);
        } else {
            std::cout << "Invalid input format. Please enter pairs in the format 'Course Name Grade'.\n";
            --i; // Decrement i to re-enter the pair.
            continue;
        }

        courses.push_back(course);
    }

    std::cout << "\nSerial Number\tCourse Name\tAssessment\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << i + 1 << "\t\t" << courses[i].courseName << "\t\t" << getAssessment(courses[i].grade) << "\n";
    }

    return 0;
}
