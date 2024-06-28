#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int isPrime(int x) {
    if (x == 2) return 1;
    if (x == 1 or x % 2 == 0) return 0;

    for (int i = 3; i < int(sqrt(x)) + 1 ; i += 2) {
        if (x % i == 0) return 0;
    }

    return 1;
}

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> factors;

    int divisor = 2;
    
    while (divisor <= n) {
        if (n % divisor == 0) {
            int count = 0;

            while (n % divisor == 0) {
                n /= divisor;
                count++;
            }

            factors.push_back({divisor, count});
        } else {
            do {
                divisor++;
            } while (!isPrime(divisor));
        }
    }
    
    return factors;
}

int main() {
    int x;
    cin >> x;

    if (isPrime(x)) {
        cout << x << " = " << x << endl;
    } else {
        vector<pair<int, int>> result = factorize(x);

        cout << x << " = ";

        for (int i = 0; i < result.size(); i++) {
            cout << result[i].first;
            if (result[i].second > 1) {
                cout << "^" << result[i].second;
            }
            if (i < result.size() - 1) {
                cout << " x ";
            } 
        }
    }
}