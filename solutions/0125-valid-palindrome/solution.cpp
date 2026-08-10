#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int izq = 0, der = n - 1;
        while (izq <= der) {
            while (izq <= der && !isalnum(static_cast<unsigned char>(s[izq]))) izq++;
            while (izq <= der && !isalnum(static_cast<unsigned char>(s[der]))) der--;
            if (izq > der) return true;
            if (tolower(static_cast<unsigned char>(s[izq])) !=
                tolower(static_cast<unsigned char>(s[der]))) return false;
            izq++; der--;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << boolalpha;
    cout << s.isPalindrome("A man, a plan, a canal: Panama") << '\n';  // true
    cout << s.isPalindrome("race a car") << '\n';                      // false
    cout << s.isPalindrome(" ") << '\n';                               // true
    cout << s.isPalindrome("0P") << '\n';                              // false
}
