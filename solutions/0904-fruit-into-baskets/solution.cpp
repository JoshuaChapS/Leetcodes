#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> d;
        int ans = 0;
        int l = 0;
        int r = 0;

        while(r<(int)fruits.size()){
            if(d.size()<2 || (d.size() == 2 && d.count(fruits[r]))>0){
                d[fruits[r]]++;
                ans++;
            }
            else{
                d[fruits[l]]--;
                d[fruits[r]]++;
                if(d[fruits[l]]==0) d.erase(fruits[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
