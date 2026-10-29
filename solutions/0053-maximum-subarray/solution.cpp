#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = (int)nums.size();
        int ans = nums[0];
        int sum = nums[0];
        for(int i = 1; i < n; i++){
            
            sum = max(nums[i], sum+nums[i]);
            ans = max(ans, sum);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
