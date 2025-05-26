#include <iostream>
#include <string>
#include <cctype>
#include <format>  

bool isOnlyDigit(const std::string &number);

double convertVNDToUSD(int VND, double ExchangeRate);

std::string formatWithDotSeparator(int number);

int main() {
    std::string VND;
    double ExchangeRate;

    while (true) {       
        std::cout << "Enter an integer money between 1.000.000 and 10.000.000: ";
        std::cin >> VND;

        if (VND.empty()){
            std::cout << "Error: Input is empty.\n";
            continue;
        }

        if (!isOnlyDigit(VND)){
            std::cout << "Error: Must be digits only.\n";
            continue;
        }

        int number = stoi(VND);
        if (number < 1000000 || number > 10000000){
            std::cout << "Error: Out of valid range (1.000.000 - 10.000.000).\n";
            continue;
        }

        std::cout << "Enter the exchange rate for 1 VND to USD: ";
        std::cin >> ExchangeRate;

        double USD = convertVNDToUSD(number, ExchangeRate);

        VND = formatWithDotSeparator(number);

        std::string result = std::format("{} d = ${:.2f}", VND, USD);
        std::cout << result << std::endl;
        break;
    }

    return 0;
}

bool isOnlyDigit(const std::string &number){
    for (char c : number) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

double convertVNDToUSD(int VND, double ExchangeRate){
    return static_cast<double>(VND) / ExchangeRate;
}

std::string formatWithDotSeparator(int number){
    std::string s = std::to_string(number);
    int insertPosition = static_cast<int>(s.length()) - 3;
    while (insertPosition > 0) {
        s.insert(insertPosition, ".");
        insertPosition -= 3;
    }
    return s;
}