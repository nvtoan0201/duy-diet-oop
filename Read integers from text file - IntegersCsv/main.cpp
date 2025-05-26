#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    cout << "Reading data.txt..." << endl;

    ifstream file("data.txt");
    if (!file.is_open()) {
        cout << "Cannot open file!" << endl;
        return 1;
    }

    string line;
    getline(file, line);
    file.close();

    vector<int> numbers;
    stringstream ss(line);
    string token;

    while (getline(ss, token, ',')) {
        numbers.push_back(stoi(token));
    }

    cout << "Found " << numbers.size() << " numbers." << endl;

    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
