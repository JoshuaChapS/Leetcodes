#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int n : nums) count[n]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& p : count) buckets[p.second].push_back(p.first);

        vector<int> res;
        for (int f = buckets.size() - 1; f > 0; f--) {
            for (int n : buckets[f]) {
                res.push_back(n);
                if ((int)res.size() == k) return res;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    for (int x : sol.topKFrequent(nums, 2)) cout << x << " ";
    cout << endl;
}
