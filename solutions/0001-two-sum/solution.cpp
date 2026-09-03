#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (size_t i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            seen.find(comp);
            if (seen.count(comp)) return {seen[comp], (int)i};
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;
    vector<int> a = {2, 7, 11, 15}, b = {3, 3};
    for (int x : sol.twoSum(a, 9)) cout << x << " ";
    cout << endl;
    for (int x : sol.twoSum(b, 6)) cout << x << " ";
    cout << endl;
}
