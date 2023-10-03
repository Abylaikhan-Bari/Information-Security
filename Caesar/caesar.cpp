#include <iostream>
#include <string>
using namespace std;

string CaesarCipher(const string& str, int key) {
    string result = str;

    for (char& c : result) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = static_cast<char>((c - base + key) % 26 + base);
        }
    }

    return result;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    int key;
    cout << "Enter key: ";
    cin >> key;

    string encryptedText = CaesarCipher(text, key);

    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}

