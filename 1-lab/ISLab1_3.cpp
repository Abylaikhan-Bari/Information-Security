#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words;

    std::cout << "Enter 15 words:\n";

    for (int i = 0; i < 15; ++i) {
        std::string word;
        std::cin >> word;
        words.push_back(word);
    }

    std::cout << "\nWord\tNumber of Letters\n";
    for (const std::string& word : words) {
        std::cout << word << "\t" << word.length() << "\n";
    }

    return 0;
}
