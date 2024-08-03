#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <sstream>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int calculateMedian(vector<int> numbers) {
    vector<int> copyList = numbers; 
    insertionSort(copyList);

    int n = copyList.size();
    int medianIndex;

    if (n%2 == 0) { //Even List floor down
        medianIndex = (n / 2) - 1; 
    } else {
        medianIndex = n / 2;
    }

    return copyList[medianIndex];
}

void displayChains(vector<list<int>> hashTable, int maxLength) {
    for (int i = 0; i < hashTable.size(); i++) {
        if (hashTable[i].size() == maxLength) {
            for (int num : hashTable[i]) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    vector<int> numbers;
    string inputLine;

    getline(cin, inputLine);
    stringstream ss(inputLine);
    int num;

    while (ss >> num) {
        numbers.push_back(num);
    }

    int median = calculateMedian(numbers);
    int hashSize = median;

    vector<list<int>> hashTable(hashSize);

    for (int number : numbers) {
        int hashIndex = number % median;
        hashTable[hashIndex].push_front(number);
    }

    int maxLength = 0;
    for (list<int> chain : hashTable) {
        if (chain.size() > maxLength) {
            maxLength = chain.size();
        }
    }

    displayChains(hashTable, maxLength);

    return 0;
}
