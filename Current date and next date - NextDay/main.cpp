#include <iostream>
#include <ctime>
#include <iomanip>

int main(){
    time_t now = time(0);
    tm *date = localtime(&now);

    std::cout << "Current date (VN format): ";
    std::cout << std::put_time(date, "%d/%m/%Y") << "\n";

    date->tm_mday += 1;
    mktime(date);

    std::cout << "Next date (US format): ";
    std::cout << std::put_time(date, "%m/%d/%y") << "\n";
    return 0;
}