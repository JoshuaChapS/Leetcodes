#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(this->s2.empty()) this->s2.push(value);
        else this->s2.push(min(value, this->s2.top()));
        this->s1.push(value);
    }
    
    void pop() {
        this->s1.pop();
        this->s2.pop();
    }
    
    int top() {
        return this->s1.top();
    }
    
    int getMin() {
        return this->s2.top();
    }
private:
    stack<int> s1, s2;
};

int main() {
    MinStack sol;
    // pruebas locales aquí
    return 0;
}
