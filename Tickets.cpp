#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void printStacks(vector<string> line, vector<string> jar) {
    string lineResult, bottleResult;
    int jarSize = jar.size();
    int lineSize = line.size();

    if (lineSize == 0) {
        lineResult = "Line Is Empty";
    } else {
        for (int i = 0; i < lineSize; i++) {
            lineResult += line[i] + " ";
        }
    }

    if (jarSize == 0) {
        bottleResult = "Bottle Is Empty";
    } else {
        for (int i = 0; i < jarSize; i++) {
            bottleResult += jar[i] + " ";
        }
    }

    cout << "Remaining Tickets In The Line: " << lineResult << endl;
    cout << "Remaining Tickets In The Bottle: " << bottleResult << endl;
    cout << "====================" << endl;
}

int main() {
    vector<string> jarTickets;
    vector<string> inlineTickets;

    string input;
    getline(cin, input);

    istringstream iss(input);
    string word;

    while (iss >> word) {
        jarTickets.push_back(word);
    }

    while (1) {
        char command;
        cin >> command;

        if (command == 'E' || command == 'e') {
            if (jarTickets.size() != 0) {
                string hold = jarTickets.back();
                inlineTickets.push_back(hold);
                jarTickets.pop_back();
            }
        } else if (command == 'D' || command == 'd') {
            if (inlineTickets.size() != 0) {
                string hold = inlineTickets.front();
                jarTickets.push_back(hold);
                inlineTickets.erase(inlineTickets.begin());
            }
        } else if (command == 'P' || command == 'p') {
            printStacks(inlineTickets, jarTickets);
        } else if (command == 'Q' || command == 'q') {
            return 0;
        } else {
            cout << "Input Error" << endl;
            return 0;
        }
    }
}