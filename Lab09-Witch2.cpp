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

void deleteContact(vector<string>& names, vector<string>& numbers, const string& nameToDelete) {
    int index = binarySearch(names, nameToDelete);
    if (index != -1) {
        names.erase(names.begin() + index); 
        numbers.erase(numbers.begin() + index);
        cout << "Deleting " << nameToDelete << "..." << endl;
    } else {
        cout << "Contact not found." << endl;
    }
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
        string name, command;
        int spacePos = inputLine.find(' ');

        command = inputLine.substr(0, spacePos);
        name = inputLine.substr(spacePos + 1);

        if (command == "F" || command == "f") {
            int index = binarySearch(names, name);
            if (index != -1) {
                cout << numbers[index] << endl;
            } else {
                cout << "Contact not found." << endl;
            }            
        } else if (command == "D" || command == "d") { 
            deleteContact(names, numbers, name);
        } else {
            cout << "ERROR!" << endl;
        }
    }

    cout << "-------------------------" << endl;

    cout << "PREORDER TRAVERSAL" << endl;

    return 0;
}
