#include <iostream>

int main() {
    int num = 10;
    int* ptr = &num;

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value of num using pointer: " << *ptr << std::endl;
    std::cout << "Address of num using pointer: " << ptr << std::endl;

delete ptr;
    return 0;
}

