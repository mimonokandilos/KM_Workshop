#include <iostream>

int main() {
    int num = 10;

    if (num > 0) {
        std::cout << "Positive number" << std::endl;
    } else if (num < 0) {
        std::cout << "Negative number" << std::endl;
    } else {
        std::cout << "Zero" << std::endl;
    }

    return 0;
}

