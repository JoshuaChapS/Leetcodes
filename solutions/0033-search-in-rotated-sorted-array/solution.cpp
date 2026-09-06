#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = (int)nums.size() - 1;
        int m;
        while(l<=r){
            m = l + (r-l)/2;
            if(nums[m] == target) return m;
            if(nums[m] >= nums[l]){
                if(nums[m] > target && nums[l]<= target) r = m-1;
                else l = m+1;
            }
            else{
                if(nums[m] < target && nums[r]>=target)l = m+1;
                else r = m-1;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
