#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> esta;
        esta[0]++;
        int n = (int)nums.size();
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum+=nums[i];
            if(esta.count(sum-k)) ans+=esta[sum-k];
            esta[sum]++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
