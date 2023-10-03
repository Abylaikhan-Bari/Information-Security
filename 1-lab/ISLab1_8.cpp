#include <iostream>
#include <complex>
#include <vector>

int main() {
    std::vector<std::complex<double>> complexNumbers;

    std::cout << "Enter 10 complex numbers (e.g., 3+4i):\n";

    for (int i = 0; i < 10; ++i) {
        double realPart, imagPart;
        char plusSign, iSymbol;

        std::cin >> realPart >> plusSign >> imagPart >> iSymbol;

        if (plusSign == '+' && iSymbol == 'i') {
            complexNumbers.push_back(std::complex<double>(realPart, imagPart));
        } else {
            std::cout << "Invalid input. Please enter a complex number in the form 'a+bi'.\n";
            --i; // Decrement i to re-enter the complex number.
        }
    }

    std::cout << "\nModulus\tImaginary Part\tReal Part\n";
    for (int i = 0; i < 10; ++i) {
        double modulus = std::abs(complexNumbers[i]);
        double imagPart = complexNumbers[i].imag();
        double realPart = complexNumbers[i].real();

        std::cout << modulus << "\t" << imagPart << "\t\t" << realPart << "\n";
    }

    return 0;
}
