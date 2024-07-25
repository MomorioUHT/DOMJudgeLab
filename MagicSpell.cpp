#include <iostream>
#include <string>
#include <vector>
using namespace std;

void evaluateEquation(string equation, vector<int>& coeffSet, bool flipped, char last_op) {
    int coeff = 1;

    if (!equation.empty() && equation[0] == '-') {
        coeff = -1;
        equation = equation.substr(1);
    } else if (!equation.empty() && equation[0] == '+') {
        equation = equation.substr(1);
    }

    if (equation.empty()) {
        return;
    }

    int len = equation.size();
    int sign = (last_op == '+' ? 1 : -1) * (flipped ? -1 : 1);

    if (equation.find("x^2") != string::npos) {
        string coeff_str = equation.substr(0, equation.find("x^2"));
        coeff *= (coeff_str.empty() || coeff_str == "-" ? 1 : stoi(coeff_str));
        coeffSet[0] += sign * coeff;
    } else if (equation.find("x") != string::npos) {
        string coeff_str = equation.substr(0, equation.find("x"));
        coeff *= (coeff_str.empty() || coeff_str == "-" ? 1 : stoi(coeff_str));
        coeffSet[2] += sign * coeff;
    } else if (equation.find("y^2") != string::npos) {
        string coeff_str = equation.substr(0, equation.find("y^2"));
        coeff *= (coeff_str.empty() || coeff_str == "-" ? 1 : stoi(coeff_str));
        coeffSet[1] += sign * coeff;
    } else if (equation.find("y") != string::npos) {
        string coeff_str = equation.substr(0, equation.find("y"));
        coeff *= (coeff_str.empty() || coeff_str == "-" ? 1 : stoi(coeff_str));
        coeffSet[3] += sign * coeff;
    } else {
        coeffSet[4] += sign * stoi(equation);
    }
}

void shortenTheEquation(string text, vector<int>& coeffSet) {
    string temp;
    char last_op = '+';
    bool flipped = false;

    int start = 0, pos = 0;

    while ((pos = text.find_first_of("+-=", start)) != string::npos) {
        if (start != pos) {
            temp = text.substr(start, pos - start);
            evaluateEquation(temp, coeffSet, flipped, last_op);
        }
        if (text[pos] == '=') {
            flipped = !flipped;
            last_op = '+';
        } else {
            last_op = text[pos];
        }
        start = pos + 1;
    }

    if (start < text.size()) {
        temp = text.substr(start);
        evaluateEquation(temp, coeffSet, flipped, last_op);
    }
}

int Calculate(const vector<int>& coeffSet, int x, int y) {
    int result = 0;
    result += coeffSet[0] * x * x;
    result += coeffSet[1] * y * y;
    result += coeffSet[2] * x;
    result += coeffSet[3] * y;
    result += coeffSet[4];
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> data(n);

    for (int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
    }

    string equation;
    cin >> equation;

    vector<int> coeffSet = {0, 0, 0, 0, 0}; // x^2, y^2, x, y, constant
    shortenTheEquation(equation, coeffSet);

    string resultText = "";

    for (int i = 0; i < n; i++) {
        resultText += "(";
        resultText += to_string(data[i].first);
        resultText += ", ";
        resultText += to_string(data[i].second);
        resultText += ") ";

        if (Calculate(coeffSet, data[i].first, data[i].second) == 0) {
            resultText += "TRUE";
        } else {
            resultText += "FALSE";
        }

        resultText += "\n";
    }

    cout << resultText;

    return 0;
}
