#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

void printDouble(const std::string& fraction) {
    std::regex pattern(R"((\d+)\s*/\s*(\d+))");
    std::smatch matches;

    if (std::regex_match(fraction, matches, pattern)) {
        int numerator = std::stoi(matches[1].str());
        int denominator = std::stoi(matches[2].str());

        if (denominator == 0) {
            std::cout << "Error: denominator cannot be zero." << std::endl;
            return;
        }

        double result = static_cast<double>(numerator) / denominator;

        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    } else {
        std::cout << "Invalid fraction format!" << std::endl;
    }
}

int main() {
    printDouble("12/8");
    return 0;
}
