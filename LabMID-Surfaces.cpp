#include <iostream>
#include <vector>
#include <string>
using namespace std;

int removeSpaceFromInt(string text) {
    string result;
    for (char s: text) {
        if (!isspace(s)) {
            result += s;
        }
    }
    return stoi(result);
}

int countX(const string& n) {
    int count = 0;
    for (char x : n) {
        if (x == 'X') count++;
    }
    return count;
}

int main() {
    vector<int> data;

    while (true) {
        string text1;
        getline(cin, text1);

        int n = removeSpaceFromInt(text1);
        
        if (n == 0) break;

        vector<int> tempArr;

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            string inp;
            cin.ignore();
            getline(cin, inp);

            int xAmount = countX(inp);
            tempArr.push_back(xAmount);
            if (xAmount > maxLen) maxLen = xAmount;
        }

        int missing = 0;
        for (int i = 0; i < n; i++) {
            missing += maxLen - tempArr[i];
        }
        data.push_back(missing);
    }

    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << endl;
    }

    return 0;
}
