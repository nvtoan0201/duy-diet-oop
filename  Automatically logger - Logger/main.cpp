#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

void log(const std::string &message);

int main(){   
    log("Exception tại hàm export. Lí do: Invalid input exception");
    return 0;
}

void log(const std::string &message) {

    time_t now = time(0);
    tm *date = localtime(&now);

    std::stringstream fileNameStream;
    fileNameStream << "log-" << std::put_time(date, "%y%m%d") << ".txt";
    std::string fileName = fileNameStream.str();

    std::ofstream logFile(fileName, std::ios::app);
    if (logFile.is_open()){
        logFile << message << "\n";
        logFile.close();
    } 
    else{
        std::cerr << "Không thể mở file log!\n";
    }
}