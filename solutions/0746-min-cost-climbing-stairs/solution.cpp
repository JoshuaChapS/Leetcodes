#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> steps((int)cost.size() + 1, 0);

        for(int i = 2; i <= (int)cost.size(); i++){
            steps[i] = min(steps[i-2] + cost[i-2], steps[i-1] + cost[i-1]);
        }
        
        return steps[(int)cost.size()];
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
