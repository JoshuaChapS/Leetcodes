#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastSeen(26, -1);
        int n = (int)s.size();
        for (int i = 0; i < n; i++){
            lastSeen[s[i]-'a'] = i;
        }

        vector<int> ans;
        int part = 1;
        int i= 0;
        int last = -1;
        while(i < n){
            last = max(lastSeen[s[i]-'a'], last);
            if(last == i){
                ans.push_back(part);
                part = 0;
            }
            part++;
            
            i++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
