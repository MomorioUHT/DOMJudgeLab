#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<vector<string>> shelf;
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        
        int amount;
        cin >> amount;

        vector<string> temp;
        for (int j = 0; j < amount; j++) {
            string bookChar;
            cin >> bookChar;
            temp.push_back(bookChar);
        }

        shelf.push_back(temp);
    }

    if (m == 0) {
        cout << "0" << endl;
        return 0;
    }

    if (m > n) {
        m = n;
    }

    int allPicks = 0;

    for (int i = 0; i < m; i++) {
        allPicks += shelf[n - 1 - i].size();
    }

    cout << allPicks << endl;

    for (int i = 0; i < m; i++) {
        vector<string> temp2 = shelf.back();
        shelf.pop_back();
        for (int j = 0; j < temp2.size(); j++) {
            cout << temp2[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
