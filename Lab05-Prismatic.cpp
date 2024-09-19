#include <iostream>
#include <vector>
using namespace std;

void Emerald(double, vector<int>&);
void Amethyst(double, vector<int>&);
void Aquamarine(double, vector<int>&);
void Amber(double, vector<int>&);

void Emerald(double val, vector<int>& stone) {
    if (val <= 1) return;

    if (val <= 20) {
        stone[3] += 1;
        Amber(val-1, stone);
    } else if (val <= 50) {
        stone[2] += 1;
        Aquamarine(0.8*val, stone);
    } else if (val > 50) {
        stone[1] += 1;
        Amethyst(0.5*val, stone);
    }
    return;
}

void Amethyst(double val, vector<int>& stone) {
    if (val <= 1) return;

    stone[0] += 1;
    stone[2] += 1;
    Aquamarine(0.7*val, stone);
    Emerald(0.3*val, stone);
    return;
}

void Aquamarine(double val, vector<int>& stone) {
    if (val <= 1) return;

    if (val >= 100) {
        stone[3] += 1;
        Amber(0.9*val, stone);
    } else if (val < 100 && val >= 10) {
        stone[1] += 1;
        Amethyst(val-10, stone);
    }
    return; // Not enough
}

void Amber(double val, vector<int>& stone) {
    if (val <= 1) return;

    stone[0] += 1;
    stone[1] += 1;
    stone[2] += 1;
    Emerald(0.1*val, stone);
    Amethyst(0.15*val, stone);
    Aquamarine(0.25*val, stone);
    return;
}

int main() {
    vector<int> stone = {0, 0, 0, 0};
    double start;
    cin >> start;

    if (start <= 1) {
        cout << "0 0 0 0" << endl;
    } else {
        stone[0] += 1;
        Emerald(start-1, stone);

        for (int i = 0; i < 4; i++) {
            cout << stone[i] << " ";
        }
    }

    return 0;
}
