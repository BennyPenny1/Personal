#include <iostream>

int main() {
    float numerator;
    float denom;
    while (true) {
        try {
            std::cout << "numerator: ";
            std::cin >> numerator;
            if (numerator == 0) {
                throw "numerator cant be zero";
            }

            break;
        }
        catch (const char* e) {
            std::cout << "error " << e << std::endl;
        }
    }
    while (true) {
        try {
            std::cout << "denominator ";
            std::cin >> denom;
            if (denom == 0) {
                throw "denominator cant be zero";
            }

            break;
        }
        catch (const char* e) {
            std::cout << "error " << e << std::endl;
        }
    }
    std::cout << "division! " << numerator / denom << "\n";
}
