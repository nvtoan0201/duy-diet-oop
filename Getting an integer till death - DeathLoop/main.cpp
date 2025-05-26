#include <iostream>
#include <string>
#include <cctype>
#include <format>

bool isOnlyDigits(const std::string& input){
    for(char c : input){
        if(!isdigit(c)){
            return false;
        }
    }
    return !input.empty();
}

int main(){
    std::string input;
    int number;
    while(true){
        std::cout << "Enter an integer between 1 and 10: ";
        std::getline(std::cin, input);

        if(input.empty()){
            std::cout << "Error: Input can not be empty.\n!";
            continue;
        }

        if(!isOnlyDigits(input)){
            std::cout << "Error: Input must contain only digit.\n";
            continue;
        }

        number = stoi(input);

        if(number < 1 || 10 < number){
            std::cout << "Error: Number must be between 1 and 10.\n";
            continue;
        }

        break;
    }
    
    std::cout << "Your entered: " << number << "\n";

    return 0;
}