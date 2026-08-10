#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int i = 0;
        while (i < n - 2) {
            int izq = i + 1, der = n - 1;
            while (izq < der) {
                int total = nums[i] + nums[izq] + nums[der];
                if (total > 0) der--;
                else if (total < 0) izq++;
                else {
                    sol.push_back({nums[i], nums[izq], nums[der]});
                    while (izq < der && nums[izq + 1] == nums[izq]) izq++;
                    izq++;
                }
            }
            while (i < n - 2 && nums[i + 1] == nums[i]) i++;
            i++;
        }
        return sol;
    }
};

int main() {
    Solution s;
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    for (auto& t : s.threeSum(v)) {
        cout << '[';
        for (int x : t) cout << x << ' ';
        cout << "] ";
    }
    cout << '\n';   // [-1 -1 2 ] [-1 0 1 ]
}
