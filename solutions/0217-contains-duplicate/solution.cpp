#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.count(n)) return true;
            seen.insert(n);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 2, 3, 1}, b = {1, 2, 3, 4};
    cout << sol.containsDuplicate(a) << endl;
    cout << sol.containsDuplicate(b) << endl;
}
