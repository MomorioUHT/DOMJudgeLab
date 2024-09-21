#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int logical_tree(int n, vector<int>& leaf_values, vector<string>& operations) {
    vector<int> tree = leaf_values;

    for (string operation : operations) {
        stringstream ss(operation);
        string op;
        ss >> op;

        if (op == "NOT") {
            int node_idx;
            ss >> node_idx;
            int new_val = 1 - tree[node_idx];
            tree.push_back(new_val);
        } 
        else if (op == "OR") {
            int left_idx, right_idx;
            ss >> left_idx >> right_idx;
            int new_val = tree[left_idx] | tree[right_idx];
            tree.push_back(new_val);
        } 
        else if (op == "AND") {
            int left_idx, right_idx;
            ss >> left_idx >> right_idx;
            int new_val = tree[left_idx] & tree[right_idx];
            tree.push_back(new_val);
        }
    }

    return tree.back();
}

int main() {
    int n;
    cin >> n;

    vector<int> leaf_values(n);
    for (int i = 0; i < n; i++) {
        cin >> leaf_values[i];
    }

    vector<string> operations;
    string operation;
    cin.ignore(); 

    while (getline(cin, operation)) {
        operations.push_back(operation);
    }

    int result = logical_tree(n, leaf_values, operations);
    cout << result << endl;

    return 0;
}
