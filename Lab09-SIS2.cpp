#include <iostream>
#include <vector>

using namespace std;

bool isLeaf(const vector<int>& tree, int index) {
    return (2 * index + 1 >= tree.size() && 2 * index + 2 >= tree.size());
}

bool isHavingLeftChild(const vector<int>& tree, int index) {
    return (2 * index + 1 < tree.size()); 
}

bool isHavingRightChild(const vector<int>& tree, int index) {
    return (2 * index + 2 < tree.size()); 
}

void postOrderTraversal(vector<int>& tree, vector<int>& S, int index, int size) {
    if (index >= size) return;

    S.push_back(tree[index]);

    if (isLeaf(tree, index)) {
        return;
    }

    if (isHavingRightChild(tree, index) || isHavingLeftChild(tree, index)) {
        if (isHavingLeftChild(tree, index)) {
            postOrderTraversal(tree, S, 2 * index + 1, size);
            S.push_back(tree[index]);
        }
        if (isHavingRightChild(tree, index)) {
            postOrderTraversal(tree, S, 2 * index + 2, size);
            S.push_back(tree[index]);
        }
    }
}


void printArray(const vector<int>& arr) {
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    int numVertices;
    cin >> numVertices;

    vector<int> tree(numVertices);
    vector<int> S;  

    for (int i = 0; i < numVertices; i++) {
        tree[i] = i + 1;
    }

    postOrderTraversal(tree, S, 0, numVertices);

    int result = S[0];
    for (int i = 1; i < S.size(); i++) {
        if (i%2 == 0) {
            result += S[i];
        } else {
            result -= S[i];
        }
    }
    cout << result;

    return 0;
}
