#include <iostream>
#include <string>
#include <cctype>

// Function to count the number of prepositions in the sentence
int countPrepositions(const std::string& sentence) {
    // List of prepositions (can be expanded)
    std::string prepositions[] = {"in", "on", "under", "behind", "with"};

    int count = 0;
    std::string word;
    for (char c : sentence) {
        if (isalpha(c)) {
            word += c;
        } else if (!word.empty()) {
            for (const std::string& preposition : prepositions) {
                if (word == preposition) {
                    count++;
                    break;
                }
            }
            word.clear();
        }
    }
    return count;
}

// Function to count the number of punctuation marks in the sentence
int countPunctuationMarks(const std::string& sentence) {
    int count = 0;
    for (char c : sentence) {
        if (ispunct(c)) {
            count++;
        }
    }
    return count;
}

// Function to count the number of vowels in the sentence
int countVowels(const std::string& sentence) {
    int count = 0;
    for (char c : sentence) {
        char lowercaseChar = tolower(c);
        if (lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' || lowercaseChar == 'o' || lowercaseChar == 'u') {
            count++;
        }
    }
    return count;
}

// Function to count the number of consonants in the sentence
int countConsonants(const std::string& sentence) {
    int count = 0;
    for (char c : sentence) {
        char lowercaseChar = tolower(c);
        if (isalpha(c) && !(lowercaseChar == 'a' || lowercaseChar == 'e' || lowercaseChar == 'i' || lowercaseChar == 'o' || lowercaseChar == 'u')) {
            count++;
        }
    }
    return count;
}

// Function to count the number of words in the sentence, excluding prepositions
int countWordsWithoutPrepositions(const std::string& sentence) {
    int count = 0;
    std::string word;
    for (char c : sentence) {
        if (isalpha(c)) {
            word += c;
        } else if (!word.empty()) {
            // Check if the word is a preposition
            std::string prepositions[] = {"in", "on", "under", "behind", "with"};
            bool isPreposition = false;
            for (const std::string& preposition : prepositions) {
                if (word == preposition) {
                    isPreposition = true;
                    break;
                }
            }
            if (!isPreposition) {
                count++;
            }
            word.clear();
        }
    }
    return count;
}

// Function to count the number of occurrences of a given word in the sentence
int countOccurrences(const std::string& sentence, const std::string& wordToCount) {
    int count = 0;
    size_t pos = 0;
    while ((pos = sentence.find(wordToCount, pos)) != std::string::npos) {
        count++;
        pos += wordToCount.length();
    }
    return count;
}

int main() {
    std::string sentence;
    std::cout << "Enter sentence: ";
    std::getline(std::cin, sentence);

    int choice;
    while (true) {
        std::cout << "Sentence processing menu:" << std::endl;
        std::cout << "1. Count the number of prepositions" << std::endl;
        std::cout << "2. Count the number of punctuation marks" << std::endl;
        std::cout << "3. Count the number of vowels" << std::endl;
        std::cout << "4. Count the number of consonants" << std::endl;
        std::cout << "5. Count the number of words, excluding prepositions" << std::endl;
        std::cout << "6. Count the number of occurrences of a given word" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Select an action: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Number of prepositions: " << countPrepositions(sentence) << std::endl;
                break;
            case 2:
                std::cout << "Number of punctuation marks: " << countPunctuationMarks(sentence) << std::endl;
                break;
            case 3:
                std::cout << "Number of vowels: " << countVowels(sentence) << std::endl;
                break;
            case 4:
                std::cout << "Number of consonants: " << countConsonants(sentence) << std::endl;
                break;
            case 5:
                std::cout << "Number of words, excluding prepositions: " << countWordsWithoutPrepositions(sentence) << std::endl;
                break;
            case 6: {
                std::string wordToCount;
                std::cout << "Enter a word to count: ";
                std::cin.ignore();
                std::getline(std::cin, wordToCount);
                std::cout << "Number of occurrences of the word '" << wordToCount << "': " << countOccurrences(sentence, wordToCount) << std::endl;
                break;
            }
            case 7:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
