#include <iostream>
#include <string>

int main() {
    const std::string password = "abcdef";
    std::string input;
    int attempts = 3;

    while (attempts--) {
        std::cout << "Enter your password: ";
        std::getline(std::cin, input);

        if (input != password) {
            std::cout << "Error: Wrong password. ";
            std::cout << attempts << " attempt(s) remaining.\n";
        } else {
            std::cout << "Access granted. Welcome!\n";
            return 0;
        }
    }

    std::cout << "You have entered the wrong password 3 times.\n";
    return 0;
}
