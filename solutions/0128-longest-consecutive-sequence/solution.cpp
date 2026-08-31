#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i : s){
            if(s.count(i-1) == 0){
                int temp = 1;
                while(s.count(i+temp) == 1){
                    temp++;
                }
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
