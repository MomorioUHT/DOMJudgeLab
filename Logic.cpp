#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

bool Not(bool a) {
    return !a;
}

bool doOp(string op, bool a, bool b) {
    if (op == "/\\") return a && b;
    else if (op == "\\/") return a || b;
    else if (op == "->") return (!a) || b;
    else if (op == "<->") return a == b;
}

bool getValue(vector<pair<char, bool>> variables, char var) {
    for (auto p : variables) {
        if (p.first == var) {
            return p.second;
        }
    }
}

bool evaluatePostfix(string text, vector<pair<char, bool>> variables) {
    vector<bool> st; 

    istringstream iss(text);
    string token;

    while (iss >> token) {
        if (token.size() == 1 && isalpha(token[0])) {
            st.push_back(getValue(variables, token[0]));
        } else if (token == "~") { 
            bool a = st.back(); st.pop_back();
            st.push_back(Not(a));
        } else {
            bool b = st.back(); st.pop_back();
            bool a = st.back(); st.pop_back();
            st.push_back(doOp(token, a, b));
        }
    }

    return st.back();
}

int main() {
    int n;
    cin >> n;

    vector<pair<char, bool>> variables;

    char var = 'A';
    for (int i = 0; i < n; ++i) {
        char val;
        cin >> val;
        bool value = (val == 'T');
        variables.push_back(make_pair(var, value));
        var++;
    }

    cin.ignore(); 
    string postfixExpression;
    getline(cin, postfixExpression);

    cout << (evaluatePostfix(postfixExpression, variables) ? "T" : "F") << endl;

    return 0;
}
