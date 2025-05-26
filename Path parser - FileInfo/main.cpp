#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
    string path;
    cout << "Enter a path of a file: ";
    getline(cin, path);

    regex pattern(R"(^(.*)\\([^\\]+)\.([a-zA-Z0-9]+)$)");
    smatch matches;

    if (regex_match(path, matches, pattern)) {
        cout << "Folder: " << matches[1] << endl;
        cout << "Filename: " << matches[2] << "." << matches[3] << endl;
        cout << "Extension: " << matches[3] << endl;
    } else {
        cout << "Invalid file path format." << endl;
    }

    return 0;
}
