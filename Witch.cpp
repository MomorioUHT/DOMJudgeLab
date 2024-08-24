#include <iostream>
#include <vector>
#include <string>

using namespace std;

int binarySearch(vector<string> names, string query) {
    int low = 0;
    int high = names.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (names[mid] == query) {
            return mid; 
        }
        if (names[mid] > query) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    return -1; 
}

int main() {
    vector<string> names;
    vector<string> numbers;
    string inputLine;

    while (true) {
        getline(cin, inputLine);
        if (inputLine == "-------------------------") {
            break;
        }
        string name, number;
        int spacePos = inputLine.find(' ');
        name = inputLine.substr(0, spacePos);
        number = inputLine.substr(spacePos + 1);

        names.push_back(name);
        numbers.push_back(number);
    }

    while (getline(cin, inputLine)) {
        int index = binarySearch(names, inputLine);
        if (index != -1) {
            cout << numbers[index] << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    return 0;
}
