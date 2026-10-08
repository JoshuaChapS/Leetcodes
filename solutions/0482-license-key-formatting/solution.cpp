#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        int counter= 0;
        for(int i = (int)s.size() - 1; i>=0; i--){
            if (counter == k){
                ans.push_back('-');
                counter = 0;
            } 
            if(isalnum(s.at(i))){
                counter++;
                ans.push_back(char(toupper(s.at(i))));
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
