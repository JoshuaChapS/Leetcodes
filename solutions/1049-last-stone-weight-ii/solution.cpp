#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);
        int mitad = total/2;
        vector<bool> a(mitad+1);
        a[0] = true;
        for (auto& stone: stones){
            for (int i = mitad; i >=stone; i--){
                if(a[i-stone]) a[i] = true;
            }
        }

        for (int i = mitad; i>= 0; i--){
            if(a[i]) return total -2*i;
        }
        return total;
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}
