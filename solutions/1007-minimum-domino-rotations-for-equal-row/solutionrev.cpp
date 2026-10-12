#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = (int) tops.size();
        unordered_map<int, int>t, b, r;
        for (int i = 0; i < n; i++){
            t[tops[i]]++;
            b[bottoms[i]]++;
            if(tops[i] == bottoms[i]) r[tops[i]]++;
        }

        int a,c;
        if(t[tops[0]] + b[tops[0]] - r[tops[0]]== n){
            a = min(n - t[tops[0]],n - b[tops[0]]);
        } else a = -1;

        if(t[bottoms[0]] + b[bottoms[0]] - r[bottoms[0]]== n){
            c = min(n - b[bottoms[0]], n - t[bottoms[0]]);
        } else c = -1;

        if(c == a || a == -1) return c;
        if(c == -1) return a;
        return min(a, c);

        
        
    }
};

int main() {
    Solution sol;
    // pruebas locales aquí
    return 0;
}