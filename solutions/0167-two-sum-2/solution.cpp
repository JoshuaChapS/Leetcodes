#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int izq = 0, der = (int)numbers.size() - 1;
        while (izq < der && numbers[izq] + numbers[der] != target) {
            if (numbers[izq] + numbers[der] > target) der--;
            else izq++;
        }
        if (izq >= der) return {};
        return {izq + 1, der + 1};
    }
};

int main() {
    Solution s;
    vector<int> v = {2, 7, 11, 15};
    for (int x : s.twoSum(v, 9)) cout << x << ' ';   // 1 2
    cout << '\n';
}
