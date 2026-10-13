#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f(string val){
        char now = val.at(0);
        int m = 1;
        for(int i = 1; i < (int)val.size(); i++){
            if(val.at(i) == now) m++;
            else if(val.at(i) < now){
                now = val.at(i);
                m = 1;
            }
        }
        return m;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        

        vector<int> wf;
        for (string& word : words){
            wf.push_back(f(word));
        }
        stable_sort(wf.begin(), wf.end());
        int n = (int)wf.size();
        vector<int> ans;
        for (string& query : queries){
            int fun = f(query);
            int i = 0;
            while (i < n && fun >= wf[i])i++;
            ans.push_back(n-i);

        }
        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
