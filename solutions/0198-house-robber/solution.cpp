#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> amount(n, 0);

        if(n==1) return nums[0];
        
        if(n==2) return max(nums[0], nums[1]);

        amount[0] = nums[0];
        amount[1] = nums[1];
        
        if(n==3) return max(nums[1], nums[0]+nums[2]);
        amount[2] = nums[0]+nums[2];

        for(int i = 3; i < n; i++){
            amount[i] = nums[i] + max(amount[i-2], amount[i-3]);
        }

        return max(amount[n-1], amount[n-2]);



    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
