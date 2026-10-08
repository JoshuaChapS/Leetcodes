#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = (int)tops.size();
        unordered_map<int,int> top, bot, same;
        for (int i = 0; i < n; i++) {
            top[tops[i]]++;
            bot[bottoms[i]]++;
            if (tops[i] == bottoms[i]) same[tops[i]]++;
        }
        auto cost = [&](int x) {
            if (top[x] + bot[x] - same[x] != n) return -1;   // some domino doesn't have x
            return min(n - top[x], n - bot[x]);
        };
        int a = cost(tops[0]), b = cost(bottoms[0]);
        if (a == -1) return b;
        if (b == -1) return a;
        return min(a, b);
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
