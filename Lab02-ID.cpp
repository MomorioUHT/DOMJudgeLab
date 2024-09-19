#include <iostream>
#include <string>
#include <cctype> 
#include <vector>
using namespace std;

vector<string> separateText(string input) {
    vector<string> data;

    int length = input.length();
    string temp;
    bool appendLast = false;

    for (int i = 0; i < length; i++) {
        if (i == 0) {
            temp += input[0];
            continue;
        }

        if (isupper(input[i])) {
            if (i == length-1) {
                if (isupper(input[i-1])) {
                    temp += input[i];
                    appendLast = true;
                }
            }
            
            if (isupper(input[i-1]) && isupper(input[i+1])) {
                temp += input[i];
            } else if (islower(input[i-1]) || isdigit(input[i-1])) {
                data.push_back(temp);
                temp = "";
                temp += input[i];
            } else if (isdigit(input[i+1])) {
                temp += input[i];
            } else {
                data.push_back(temp);
                temp = "";
                temp += input[i];                
            }
        } else if (islower(input[i])) {
            if (isdigit(input[i-1])) { 
                data.push_back(temp);
                temp = "";
                temp += input[i];           
            } else {
                temp += input[i];     
            }
        } else if (isdigit(input[i])) {
            if (isdigit(input[i-1])) {
                temp += input[i];                
            } else {
                data.push_back(temp);
                temp = "";
                temp += input[i];
            }
        }
    }

    if (!appendLast) {
        data.push_back(temp);
    }

    return data;
}

int main() {
    string context;
    cin >> context;

    vector<string> result = separateText(context);

    for (int i = 0; i < result.size(); i++) {
        result[i][0] = toupper(result[i][0]);
        if (i == result.size() - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }
   
}