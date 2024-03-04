#include <iostream>
#include <fstream>

int main() {
    std::ofstream outfile("example.txt");
    if (outfile.is_open()) {
        outfile << "This is a line of text." << std::endl;
        outfile.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }

    return 0;
}

