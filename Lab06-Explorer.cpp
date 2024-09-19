#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int binarySearch(vector<int> arr, int key) {
    int n = arr.size();
    if (n == 0) return -1; 
    
    int count = 0;
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        count++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return count;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int linearSearch(vector<int> arr, int key) {
    int count = 0;
    int n = arr.size();
    if (n == 0) return -1; 

    for (int i = 0; i < arr.size(); i++) {
        count ++;
        if (arr[i] == key)
            return count;
    }
    return -1;
}

int sentinelSearch(vector<int> arr, int key) {
    int count = 0;
    int n = arr.size();
    if (n == 0) return -1; 

    for (int i = n - 1; i >= 0; i--) {
        count++;
        if (arr[i] == key)
            return count;
    }

    return -1; 
}


int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<int> data = {};
    int number;
    while (ss >> number) {
        data.push_back(number);
    }

    int search;
    cin >> search;

    int linearCount = linearSearch(data, search);
    int sentinelCount = sentinelSearch(data, search);

    sort(data.begin(), data.end());
    int binaryCount = binarySearch(data, search);

    if (linearCount == -1 && sentinelCount == -1 && binaryCount == -1) {
        cout << "Not Found" << endl;
    } else {
        string bestMethod = "";
        int minComparisons = min({binaryCount, linearCount, sentinelCount});

        if (minComparisons == linearCount) bestMethod += "Linear ";
        if (minComparisons == sentinelCount) bestMethod += "Sentinel ";
        if (minComparisons == binaryCount) bestMethod += "Binary ";

        cout << bestMethod << endl;
        cout << minComparisons << endl;
    }

    return 0;
}
