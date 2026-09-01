#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int middle;
        while(left<=right){
            middle = left + (right - left) / 2;
            if(nums[middle] == target) return middle;
            if(nums[middle] > target) right = middle - 1;
            else left = middle + 1;
        }
        return -1;

    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
