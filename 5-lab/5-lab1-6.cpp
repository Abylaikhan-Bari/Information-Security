#include <iostream>
#include <string>
#include <cctype>

// Функция для подсчета числа предлогов в предложении
int countPrepositions(const std::string& sentence) {
    // Список предлогов (может быть расширен)
    std::string prepositions[] = {"в", "на", "под", "за", "с"};

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

// Функция для подсчета числа знаков препинания в предложении
int countPunctuationMarks(const std::string& sentence) {
    int count = 0;
    for (char c : sentence) {
        if (ispunct(c)) {
            count++;
        }
    }
    return count;
}

// Функция для подсчета числа гласных букв в предложении
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

// Функция для подсчета числа согласных букв в предложении
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

// Функция для подсчета числа слов в предложении, не считая предлоги
int countWordsWithoutPrepositions(const std::string& sentence) {
    int count = 0;
    std::string word;
    for (char c : sentence) {
        if (isalpha(c)) {
            word += c;
        } else if (!word.empty()) {
            // Проверяем, является ли слово предлогом
            std::string prepositions[] = {"в", "на", "под", "за", "с"};
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

// Функция для подсчета числа вхождений заданного слова в предложение
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
    std::cout << "Введите произвольное предложение: ";
    std::getline(std::cin, sentence);

    int choice;
    while (true) {
        std::cout << "Меню обработки предложения:" << std::endl;
        std::cout << "1. Подсчитать число предлогов" << std::endl;
        std::cout << "2. Подсчитать число знаков препинания" << std::endl;
        std::cout << "3. Подсчитать число гласных" << std::endl;
        std::cout << "4. Подсчитать число согласных" << std::endl;
        std::cout << "5. Подсчитать количество слов, не считая предлоги" << std::endl;
        std::cout << "6. Подсчитать число вхождений заданного слова" << std::endl;
        std::cout << "7. Выйти" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Число предлогов: " << countPrepositions(sentence) << std::endl;
                break;
            case 2:
                std::cout << "Число знаков препинания: " << countPunctuationMarks(sentence) << std::endl;
                break;
            case 3:
                std::cout << "Число гласных: " << countVowels(sentence) << std::endl;
                break;
            case 4:
                std::cout << "Число согласных: " << countConsonants(sentence) << std::endl;
                break;
            case 5:
                std::cout << "Число слов, не считая предлоги: " << countWordsWithoutPrepositions(sentence) << std::endl;
                break;
            case 6: {
                std::string wordToCount;
                std::cout << "Введите слово для подсчета: ";
                std::cin.ignore();
                std::getline(std::cin, wordToCount);
                std::cout << "Число вхождений слова '" << wordToCount << "': " << countOccurrences(sentence, wordToCount) << std::endl;
                break;
            }
            case 7:
                return 0;
            default:
                std::cout << "Некорректный выбор. Попробуйте еще раз." << std::endl;
        }
    }

    return 0;
}
