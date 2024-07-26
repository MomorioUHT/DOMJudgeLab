#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void findAndPop(vector<string>& arr) {

}

int main() {
    string input;
    vector<string> jarTickets;
    vector<string> inLineTickets;

    getline(cin, input);

    istringstream iss(input);
    string temp;

    while (iss >> temp) {
        jarTickets.push_back(temp);
    }

    while (1) {
        char command;
        cin >> command;

        if (command == 'E' || command == 'e') {

        } else if (command == 'D' || command == 'd') {

        } else if (command == 'P' || command == 'p') {

        } else if (command == 'Q' || command == 'q') {

        } else {
            cout << "Input Error" << endl;
            break;
        }
    }

    return 0;
}
