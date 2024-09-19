#include <iostream>
#include <vector>
using namespace std;

int Tri(int n){
    if (n == 1) return 1;
    return n + Tri(n-1);
}

int Tetra(int n) {
    if (n == 1) return 1;
    return Tri(n) + Tetra(n-1);
}

int main() {
    vector<int> arr;

    int temp;
    while (cin >> temp) {
        arr.push_back(temp);
    }

    int arrSize = arr.size();
    for (int i = 0; i < arrSize; i++) {
        cout << Tetra(arr[i]) << endl;
    }
}