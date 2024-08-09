#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countX(string n) {
    int count = 0;
    for (char x: n) {
        if (x == 'X') count++;
    }
    return count;
}

int main() {
    vector<int> data;

    while (1) {
        int n;
        cin >> n;

        cin.ignore();

        if (n == 0) break;

        vector<int> tempArr;

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            string inp;
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
        if (i == data.size() - 1) cout << data[i];
        else cout << data[i] << endl;
    }

    return 0;
}
