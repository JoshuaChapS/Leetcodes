#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        int a, b;
        for (int i = 0; i < (int)tokens.size(); i++) {
            if (tokens[i] == "+") {
                b = vals.top();
                vals.pop();
                a = vals.top();
                vals.pop();
                vals.push(a + b);
            } else if (tokens[i] == "-") {
                b = vals.top();
                vals.pop();
                a = vals.top();
                vals.pop();
                vals.push(a - b);
            } else if (tokens[i] == "*") {
                b = vals.top();
                vals.pop();
                a = vals.top();
                vals.pop();
                vals.push(a * b);
            } else if (tokens[i] == "/") {
                b = vals.top();
                vals.pop();
                a = vals.top();
                vals.pop();
                vals.push(a / b);
            } else {
                vals.push(stoi(tokens[i]));
            }
        }
        return vals.top();
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
