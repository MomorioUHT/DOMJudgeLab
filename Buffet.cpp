#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int waitAmount,table;
    cin >> waitAmount >> table;

    vector<pair<int, string>> data;

    for (int i = 0; i < waitAmount; i++) {
        int level;
        string name;
        cin >> level >> name;
        data.push_back({level, name});
    }    

    if (table == 0) {
        return 0;
    }

    vector<string> top_customers;

    for (int i = 0; i < table; i++) {
        int max_level = 0;
        int max_index = -1;

        for (int j = 0; j < data.size(); j++) {
            if (data[j].first > max_level) {
                max_level = data[j].first;
                max_index = j;
            }
        }

        if (max_index != -1) {
            top_customers.push_back(data[max_index].second);
            data[max_index].first = -999999;
        }
    }

    for (string name : top_customers) {
        cout << name << endl;
    }
}