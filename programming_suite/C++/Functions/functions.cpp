#include <iostream>

int add(int a, int b) {
    return a + b;
}

float add(float a, float b) {
    return a + b;
}

int main() {
    int result1 = add(5, 10);
    float result2 = add(3.5f, 2.5f);

    std::cout << "Result 1: " << result1 << std::endl;
    std::cout << "Result 2: " << result2 << std::endl;

    return 0;
}

